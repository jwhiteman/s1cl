#include <chicken.h>

int main()
{
  C_word k = CHICKEN_run(C_toplevel);

  for(;;)
    k = CHICKEN_continue(k);

  return 0;
}
