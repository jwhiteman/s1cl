#include <chicken.h>
#include <stdio.h>

#include "1.h"

int
main()
{
  CHICKEN_run(C_toplevel);

  char *input = "49276d206b696c6c696e6720796f757220627261696e206c696b652"\
                "06120706f69736f6e6f7573206d757368726f6f6d";

  printf("result from scheme: %s\n", decodehex(input));
}
