#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "2.h"

int hex2int(char ch)
{
  if (ch >= '0' && ch <= '9')
    return ch - '0';
  if (ch >= 'A' && ch <= 'F')
    return ch - 'A' + 10;
  if (ch >= 'a' && ch <= 'f')
    return ch - 'a' + 10;
  return HEX2INT_ERROR;
}

char *
fixed_xor(char *input, char *key)
{
  char *output = malloc((strlen(input) + 1) * sizeof(char));

  for(unsigned long i = 0; i < strlen(input); i = i + 2) {
    char a1 = hex2int(input[i]);
    char b1 = hex2int(input[i + 1]);

    char a2 = hex2int(key[i]);
    char b2 = hex2int(key[i + 1]);

    char c1 = (a1 << 4) + b1;
    char c2 = (a2 << 4) + b2;

    sprintf(&output[i], "%02x", c1 ^ c2);
  }

  return output;
}
