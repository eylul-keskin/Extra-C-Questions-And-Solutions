#include <stdio.h>

#ifndef WORD_LEN
#define WORD_LEN 20
#endif

int question4(char *sourcePath, char *destPath) {
    int freq[WORD_LEN] = {0};

    FILE *fpSource, *fpDest;

    fpSource = fopen(sourcePath, "r");
    fpDest = fopen(destPath, "w");

     if(fpSource == NULL || fpDest == NULL) {
        if (fpSource != NULL) fclose(fpSource);
        if (fpDest != NULL) fclose(fpDest);
        return 0;
    }

    int len = 0;
    int ch;
    while ((ch = fgetc(fpSource)) != EOF) {
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            len++;
        } else {
            if(len > 0 && len < WORD_LEN) {
                freq[len]++;
            }
            len = 0;
        }
    }

    if (len > 0 && len < WORD_LEN) {
        freq[len]++;
    }

    for(int i = 0; i < WORD_LEN ; i++) {
        fprintf(fpDest , "Length %d: %d\n" , i , freq[i]);
    }

    fclose(fpSource);
    fclose(fpDest);
    return 1;
}