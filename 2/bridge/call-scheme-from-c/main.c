#include <chicken.h>
#include <stdio.h>

#include "2.h"

int
main()
{
  printf("uno!\n");
  CHICKEN_run(C_toplevel);

  char *input = "1c0111001f010100061a024b53535009181c";
  char *key   = "686974207468652062756c6c277320657965";

  printf("result from scheme: %s\n", fixedxor(input, key));
}
