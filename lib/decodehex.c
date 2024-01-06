#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "decodehex.h"

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
decode_hex_string(char *hex_str)
{
  int   need   = ((strlen(hex_str) / 2) + 1);
  char *output = malloc(need * sizeof(char));

  int j = 0;
  for(unsigned long i = 0; i < strlen(hex_str); i = i + 2) {
    char a = hex2int(hex_str[i]);
    char b = hex2int(hex_str[i + 1]);

    if (a == HEX2INT_ERROR || b == HEX2INT_ERROR) {
      perror("decode-hex-string error: hex2int error");
      exit(EXIT_FAILURE);
    }

    char c = (a << 4) + b;

    output[j] = c;

    j++;
  }

  return output;
}
