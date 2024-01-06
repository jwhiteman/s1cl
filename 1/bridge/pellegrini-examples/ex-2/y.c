#include <chicken.h>
#include <stdio.h>

#include "y.h"

int main() {
  CHICKEN_run(C_toplevel);

  // C_word result;
  // CHICKEN_eval_string("(begin (display ’hello) (newline))",
  //     &result);
  // printf("not sure: %lu\n", result);

  printf("%d\n", multiplica_em_scheme(5,4));
}
