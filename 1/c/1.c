#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../lib/decodehex.h"
#include "../../lib/base64.h"

// TODO: use base64
// TODO: try to call chicken from c

int
main()
{
  char *input     = "49276d206b696c6c696e6720796f757220627261696e206"\
                    "c696b65206120706f69736f6e6f7573206d757368726f6f6d";

  char *text      = decode_hex_string(input);
  char *enc_text  = b64_encode((const unsigned char *)text, strlen(text));

  printf("\n****** TEST OUTPUT ******: %s\n\n", text);
  printf("\n****** TEST OUTPUT ******: %s\n\n", enc_text);

  free(text);
  free(enc_text);
}
