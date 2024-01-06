#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>

#include "base64.h"

// NOTES:
// watch strlen for binary data - pass it in (re: hamming-distance)
// use memcpy instead of strncpy for binary data

void
decrypt(char* bytes, char* buff, size_t keysize, int key)
{
  for (size_t i = 0; i < keysize; i++) {
    buff[i] = bytes[i] ^ key;
  }

  buff[keysize] = '\0';
}

int
score(char *text)
{
  int count = 0;
  size_t length = strlen(text);

  for (size_t i = 0; i < length; i++) {
    if (text[i] == 69 || text[i] == 101 ||   // Ee
        text[i] == 84 || text[i] == 116 ||   // Tt
        text[i] == 65 || text[i] == 97 ||    // Aa
        text[i] == 79 || text[i] == 111 ||   // Oo
        text[i] == 73 || text[i] == 105 ||   // Ii
        text[i] == 78 || text[i] == 110 ||   // Nn
        text[i] == 32 ||                     // SPACE
        text[i] == 83 || text[i] == 115 ||   // Ss
        text[i] == 72 || text[i] == 104 ||   // Hh
        text[i] == 82 || text[i] == 114 ||   // Rr
        text[i] == 68 || text[i] == 100 ||   // D
        text[i] == 76 || text[i] == 108 ||   // Ll
        text[i] == 85 || text[i] == 117) {   // Uu
      count++;
    }
  }

  return count;
}
int
hamming_distance(char *str1, char *str2, size_t len)
{
  int count = 0;

  for (size_t idx = 0; idx < len; idx++) {
    int xor = str1[idx] ^ str2[idx];
    for (int bidx = 0; bidx < 8; bidx++) {
      count = count + (xor & 1);
      xor   = xor >> 1;
    }
  }

  return count;
}

int
most_likely_keysize(const char* input, int minkeysize, int maxkeysize)
{
  float minimum_hamming_distance = FLT_MAX;
  int keysize = -1;

  for (int k = minkeysize; k < maxkeysize; k++) {
    float acc  = 0.0;
    char *prev = malloc(k + 1);
    char *cur  = malloc(k + 1);

    for (int idx = 0; idx < 20 + 1; idx++) { // 20 is arbitrary. "enough times."
      memcpy(cur, input + (idx * k), k);
      cur[k] = '\0';

      if (idx > 0) {
        float normalized_hamming_distance =
          (float)hamming_distance(prev, cur, k) / (float)k;

        acc = acc + normalized_hamming_distance;
      }

      strcpy(prev, cur); // TODO: is there a more efficient way to do this?
      prev[k] = '\0';
    }

    free(prev);
    free(cur);

    acc = acc / 20.0;

    if (acc < minimum_hamming_distance) {
      minimum_hamming_distance = acc;
      keysize = k;
    }
  }

  return keysize;
}

char*
base64_file_to_bytes(const char* filename)
{
  FILE *file         = fopen(filename, "rb");
  fseek(file, 0, SEEK_END);
  long file_size     = ftell(file);
  rewind(file);

  char *buffer       = malloc((sizeof(char) * file_size + 1));
  size_t bytes_read  = fread(buffer, 1, file_size, file);
  buffer[bytes_read] = '\0';
  fclose(file);

  size_t out_len     = b64_decoded_size(buffer) + 1;
  char *out          = malloc(out_len);
  if (!b64_decode(buffer, (unsigned char *)out, out_len)) {
    perror("base64 decode failure");
    abort();
  }
  out[out_len] = '\0';
  free(buffer);

  return out;
}

/*  transposed_blocks - example k = 3:
 *  k:   3
 *  i:   0      1      2
 *  j:   0 1 2  0 1 2  0 1 2
 *  idx: 0 3 6  1 4 7  2 5 8  => (k * j) + i
*/
void
transposed_blocks(char* input, int k, char blocks[][k + 1])
{
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      blocks[i][j] = input[(k * j) + i];
    }
    blocks[i][k] = '\0';
  }
}

void
crack_repeat_key_xor(int keysize, char blocks[][keysize + 1], char key[])
{
  char buf[keysize + 1];

  for (int i = 0; i < keysize; i++) {
    int maxs     = 0;
    int currents = 0;
    for (int keyguess = 0; keyguess < 127; keyguess++)  {
      decrypt(blocks[i], buf, (size_t)keysize, keyguess);

      currents = score(buf);
      if (currents > maxs) {
        maxs   = currents;
        key[i] = keyguess;
      }
    }
  }
}

int
main()
{
  char *input_bytes = base64_file_to_bytes("6-no-newlines.txt");
  int keysize       = most_likely_keysize(input_bytes, 2, 40);

  char blocks[keysize][keysize + 1];
  transposed_blocks(input_bytes, keysize, blocks);
  free(input_bytes);

  char key[keysize + 1];
  crack_repeat_key_xor(keysize, blocks, key);
  printf("%s\n", key);
}
