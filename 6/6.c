#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>

#include "base64.h"

// NOTES:
// watch strlen for binary data - pass it in (re: hamming-distance)
// use memcpy instead of strncpy for binary data

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

    for (int idx = 0; idx < 20 + 1; idx++) {
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

  size_t out_len     = b64_decoded_size(buffer)+1;
  char *out          = malloc(out_len);
  if (!b64_decode(buffer, (unsigned char *)out, out_len)) {
    perror("base64 decode failure");
    abort();
  }
  out[out_len] = '\0';
  free(buffer);

  return out;
}

int
main()
{
  char *input_bytes = base64_file_to_bytes("6-no-newlines.txt");

  printf("keysize: %i\n", most_likely_keysize(input_bytes, 2, 40));

  free(input_bytes);
}
