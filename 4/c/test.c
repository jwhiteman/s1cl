char *input    = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
size_t textbfs = (strlen(input) / 2) + 1;
char textbf[textbfs];
decrypt(input, textbf, textbfs, 88);
printf("%s\n", textbf);
printf("textbfs: %i\n", (int)textbfs);
