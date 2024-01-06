#include <stdio.h>
#include <stdlib.h>
#include "decodehex.h"

int
main()
{
  char *input  = "49276d206b696c6c696e6720796f757220627261696e206"\
                 "c696b65206120706f69736f6e6f7573206d757368726f6f6d";

  char *output = decode_hex_string(input);

  printf("the result is: %s\n", output);

  free(output);
  // free(output); // to induce "pointer being freed was not allocated" error
}
