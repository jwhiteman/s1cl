#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>

#include "base64.h"

void
handleErrors(void) {
  ERR_print_errors_fp(stderr);
  abort();
}

int
decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
        unsigned char *plaintext)
{
  EVP_CIPHER_CTX *ctx;
  int len;
  int plaintext_len;

  if (!(ctx = EVP_CIPHER_CTX_new()))
    handleErrors();

  if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_128_ecb(), NULL, key, NULL))
    handleErrors();

  if (1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
    handleErrors();

  plaintext_len = len;

  if (1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len))
    handleErrors();

  plaintext_len += len;

  EVP_CIPHER_CTX_free(ctx);

  return plaintext_len;
}

char*
read_no_newlines(const char* filename)
{
  FILE *file = fopen(filename, "rb");

  fseek(file, 0, SEEK_END);
  long length = ftell(file);
  rewind(file);

  char *content = malloc(length);

  char c;
  size_t content_size = 0;
  while ((c = fgetc(file)) != EOF) {
    if (c != '\n') {
      content[content_size++] = c;
    }
  }
  fclose(file);

  content[content_size] = '\0';

  return content;
}

char*
base64_decode(char* input)
{
  size_t out_len     = b64_decoded_size(input) + 1;
  char *out          = malloc(out_len);
  b64_decode(input, (unsigned char *)out, out_len);
  out[out_len] = '\0';

  return out;
}

int
main()
{
  unsigned char key[]      = "YELLOW SUBMARINE";
  char *input              = read_no_newlines("7.txt");

  char *bytes              = base64_decode(input);
  size_t buflen            = b64_decoded_size(input);

  unsigned char *plaintext = malloc(buflen + 1);

  decrypt((unsigned char*)bytes, (int)buflen, key, plaintext);

  printf("%s\n", plaintext);

  free(input);
  free(bytes);
  free(plaintext);
}
