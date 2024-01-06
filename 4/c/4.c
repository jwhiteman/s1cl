#include <stdio.h>
#include <string.h>

int
hex2int(char hex)
{
  if (hex >= '0' && hex <= '9')
    return hex - '0';
  if (hex >= 'a' && hex <= 'z')
    return hex - 'a' + 10;
  if (hex >= 'A' && hex <= 'Z')
    return hex - 'A' + 10;

  printf("hex2int error!!! %i\n", (int)hex);
  return -1;
}

void
decrypt(char* text, char* buff, size_t bufflen, char key)
{
  for (size_t i = 0; i < (bufflen - 2); i++) {
    int unibble = hex2int(text[2*i]) << 4;
    int lnibble = hex2int(text[(2*i + 1)]);

    buff[i] = (unibble + lnibble) ^ key;
  }

  buff[bufflen - 1] = '\0';
}

int
score(char *text)
{
  int count = 0;
  size_t length = strlen(text);

  for (size_t i = 0; i < length; i++) {
    if (text[i] == 69 || text[i] == 101 ||   // Ee
        text[i] == 84 || text[i] == 116 ||   // Tt
        text[i] == 65 || text[i] == 97 ||    // Aa
        text[i] == 79 || text[i] == 111 ||   // Oo
        text[i] == 73 || text[i] == 105 ||   // Ii
        text[i] == 78 || text[i] == 110 ||   // Nn
        text[i] == 32 ||                     // SPACE
        text[i] == 83 || text[i] == 115 ||   // Ss
        text[i] == 72 || text[i] == 104 ||   // Hh
        text[i] == 82 || text[i] == 114 ||   // Rr
        text[i] == 68 || text[i] == 100 ||   // D
        text[i] == 76 || text[i] == 108 ||   // Ll
        text[i] == 85 || text[i] == 117) {   // Uu
      count++;
    }
  }

  return count;
}

int
main()
{

  FILE *file;
  file = fopen("4.txt", "r");

  size_t linebfs = 62;
  char linebf[linebfs];

  size_t textbfs = 31;
  char textbf[textbfs];
  char msg[textbfs];

  int maxs = 0;
  int currents = 0;
  while (fgets(linebf, linebfs, file) != NULL) {
    for (int key = 0; key < 127; key++)  {
      decrypt(linebf, textbf, textbfs, key);

      currents = score(textbf);
      if (currents > maxs) {
        maxs = currents;
        strcpy(msg, textbf);
      }
    }
  }

  printf("%i %s\n", maxs, msg);

  fclose(file);
}
