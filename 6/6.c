#include <stdio.h>
#include <string.h>

int
hamming_distance(char *str1, char *str2)
{
  int count = 0;
  size_t len = strlen(str1);

  for (size_t idx = 0; idx < len; idx++) {
    int xor = str1[idx] ^ str2[idx];
    for (int bidx = 0; bidx < 8; bidx++) {
      count = count + (xor & 1);
      xor   = xor >> 1;
    }
  }

  return count;
}

int
main()
{
  printf("the result: %i\n", hamming_distance("this is a test", "wokka wokka!!!"));
}
