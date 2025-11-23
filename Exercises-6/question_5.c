#include <stdio.h>

#ifndef BUF_LEN
#define BUF_LEN 1000 
#endif

int question5(char *sourcePath, char *destPath) {
    
    FILE *fpSource, *fpDest;
    fpSource = fopen(sourcePath, "r");
    fpDest = fopen(destPath, "w");

    if(fpSource == NULL || fpDest == NULL) {
        if(fpSource != NULL) fclose(fpSource);
        if(fpDest != NULL) fclose(fpDest);
        return 0;
    }

    char buffer[BUF_LEN];
    while (fgets(buffer, BUF_LEN, fpSource) != NULL) {
        if(buffer[0] >= 'a' && buffer[0] <= 'e') {
            fputs(buffer, fpDest);
        } 
    }

    fclose(fpSource);
    fclose(fpDest);
    return 1;
}
