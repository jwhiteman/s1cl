#include <stdio.h>
#include <string.h>
#include <pcre.h>

int
hex2int(char hex)
{
  if (hex >= '0' && hex <= '9')
    return hex - '0';
  if (hex >= 'a' && hex <= 'z')
    return hex - 'a' + 10;
  if (hex >= 'A' && hex <= 'A')
    return hex - 'A' + 10;
  return -1;
}

int
score(char* decrypted_text)
{
  const char *error;
  int erroffset;
  pcre *re;
  re = pcre_compile("[etaoin shrdlu]", PCRE_CASELESS, &error, &erroffset, NULL);
  if (re == NULL) {
    printf("PCRE compilation failed at offset %d: %s\n", erroffset, error);
    return 1;
  }

  int ovector[30];
  int subject_length = strlen(decrypted_text);
  int match_count    = 0;
  int offset         = 0;

  while (offset < subject_length && pcre_exec(re, NULL, decrypted_text, subject_length, offset, 0, ovector, 30) >= 0) {
    match_count++;
    offset = ovector[1];
  }
  pcre_free(re);

  return match_count;
}

int
main()
{
  char *input = "1b37373331363f78151b7f2b783431333d7839"\
                "7828372d363c78373e783a393b3736";

  int message_size = (strlen(input) / 2) + 1;
  char buf[message_size];
  char msg[message_size];

  int current_score, max = 0;

  for(int key = 0; key < 127; key++) {
    for(int idx = 0; idx < message_size-1; idx++) {
      int a = hex2int(input[2*idx]) << 4;
      int b = hex2int(input[2*idx+1]);

      buf[idx] = key ^ (a + b);
    }

    buf[message_size - 1] = '\0';
    current_score = score(buf);

    if (current_score > max) {
      max = current_score;
      strcpy(msg, buf);
    }
  }

  printf("%s\n", msg); // Cooking MC's like a pound of bacon
}
