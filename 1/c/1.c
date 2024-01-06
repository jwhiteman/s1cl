#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../lib/decodehex.h"

// TODO: try to call from chicken
// TODO: use base64

int
main()
{
  char *input  = "49276d206b696c6c696e6720796f757220627261696e206"\
                 "c696b65206120706f69736f6e6f7573206d757368726f6f6d";
  char *output = decode_hex_string(input);

  printf("\n****** TEST OUTPUT ******: %s\n\n", output);

  free(output);

  return 0;
}
