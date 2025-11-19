#include <stdio.h>

#ifndef CHAR_NUM
#define CHAR_NUM 26
#endif

int question3(char *sourcePath, char *destPath) {
    int freq[CHAR_NUM] = {0};

    FILE *fpSource, *fpDest;
    fpSource = fopen(sourcePath, "r");
    fpDest = fopen(destPath, "w");

    if(fpSource == NULL || fpDest == NULL) {
        if (fpSource != NULL) fclose(fpSource);
        if (fpDest != NULL) fclose(fpDest);
        return 0;
    }

    int ch;
    while ((ch = fgetc(fpSource)) != EOF) {
        if (ch >= 'a' && ch <= 'z') {
            ch = ch - 32;
        }

        if (ch >= 'A' && ch <= 'Z') {
            int n = ch - 'A'; 
            freq[n]++;
        }
    }

   for (int i = 0; i < CHAR_NUM; i++) {
        fprintf(fpDest, "%c: %d\n", 'A' + i, freq[i]);
    }

    fclose(fpSource);
    fclose(fpDest);

    return 1;
}