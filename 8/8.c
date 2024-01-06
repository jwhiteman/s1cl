#include <stdio.h>
#include <string.h>

#include <unistd.h>

#define NUM_BLOCKS_PER_LINE 10
#define BLOCK_LENGTH 32
#define TERMINATED_BLOCK_LENGTH 32 + 1

int
main()
{
  FILE *file = fopen("8.txt", "r");

  size_t linebfs = NUM_BLOCKS_PER_LINE * BLOCK_LENGTH + 1;
  char linebf[linebfs];

  int linenum = 1;
  while (fgets(linebf, linebfs, file) != NULL) {
    fgetc(file); // hack - eat the newline

    char blocks[NUM_BLOCKS_PER_LINE][TERMINATED_BLOCK_LENGTH];

    for (int i = 0; i < NUM_BLOCKS_PER_LINE; i++) {
      strncpy(blocks[i], linebf + i * BLOCK_LENGTH, TERMINATED_BLOCK_LENGTH);

      blocks[i][BLOCK_LENGTH] = '\0';

      // if i had a hash handy...but i don't, so...
      for (int j = 0; j < i; j++) {
        if (strcmp(blocks[i], blocks[j]) == 0) {
          printf("duplicate blocks detected on line %i\n", linenum);
          break;
        }
      }
    }

    linenum++;
  }

  fclose(file);
}
// output:
// duplicate blocks detected on line 133
// duplicate blocks detected on line 133
// duplicate blocks detected on line 133
