#include <stdio.h>
#include <string.h>

/*
 * TODO: run this w/ lldb and investigate what everything looks like
*/

int
main()
{
  char *alpha = "abcdefghijklmnopqrstuvwxyz";

  int minkeysize      = 2;
  int maxkeysize      = 5;
  int numcalculations = 4;

  for (int k = minkeysize; k < maxkeysize; k++) {
    char prev[k + 1], cur[k + 1];

    for (int idx = 0; idx < numcalculations; idx++) {
      strncpy(cur, alpha + (idx * k), k);
      cur[k] = '\0';

      if (idx > 0) {
        printf("k:%i prev:%s: cur:%s\n", k, prev, cur);
      }

      strcpy(prev, cur);
    }
  }
}
