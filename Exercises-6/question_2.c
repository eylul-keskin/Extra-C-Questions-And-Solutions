#include "stdio.h"

int question2(char *sourcePath, char *destPath) {
    FILE *fpSource, *fpDest;
    int ch;

    fpSource = fopen(sourcePath, "r");
    fpDest = fopen(destPath, "w");

    if(fpSource == NULL || fpDest == NULL) {
        if (fpSource != NULL) fclose(fpSource);
        if (fpDest != NULL) fclose(fpDest);
        return 0;
    }

    while ((ch = fgetc(fpSource)) != EOF) 
    {
        if(ch >='a' && ch <= 'z') {
            ch = ch - 32;
        }
        fputc(ch, fpDest);

    }
    fclose(fpSource);
    fclose(fpDest);

    return 1;
}