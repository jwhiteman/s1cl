// test out
FILE* outfile = fopen("haha.bin", "wb");
fwrite(out, 1, out_len, outfile);
fclose(outfile);

// test hamming distance
printf("the result: %i\n", hamming_distance("this is a test", "wokka wokka!!!"));

// test in-slices
char *alpha = "abcdefghijklmnopqrstuvwxyz";

int minkeysize      = 2;
int maxkeysize      = 5;
int numcalculations = 4;

for (int k = minkeysize; k < maxkeysize; k++) {
  char prev[k + 1], cur[k + 1];

  for (int idx = 0; idx < numcalculations; idx++) {
    strncpy(cur, alpha + (idx * k), k);
    cur[k] = '\0';

    if (idx > 0)
      printf("k:%i prev: %s: cur:%s\n", k, prev, cur);

    strcpy(prev, cur);
  }
}
