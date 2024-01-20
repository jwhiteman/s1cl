#include <stdio.h>
#include <string.h>

#define HEX_CHAR_PER_BYTE 2

void
encrypt(const char* input, size_t inputln, const char* key,
        size_t keyln, char* buffer, size_t bufferln)
{
  for (size_t idx = 0; idx < inputln; idx++) {
    int encrypted_byte = input[idx] ^ key[idx % keyln];

    snprintf(&buffer[idx * HEX_CHAR_PER_BYTE], 3, "%02x", encrypted_byte);
  }

  buffer[bufferln] = '\0';
}

int
main()
{
  const char *input = "Burning 'em, if you ain't quick and nimble\n"\
                      "I go crazy when I hear a cymbal";
  size_t inputln    = strlen(input);

  const char *key   = "ICE";
  size_t keyln      = strlen(key);

  size_t bufferln   = (inputln * HEX_CHAR_PER_BYTE) + 1;
  char buffer[bufferln];

  encrypt(input, inputln, key, keyln, buffer, bufferln);

  printf("%s\n", buffer);
}
