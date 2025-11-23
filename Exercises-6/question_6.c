#include <stdio.h>

#ifndef BUF_LEN
#define BUF_LEN 1000 
#endif

int question6(char *sourcePath, char *destPath) {

    FILE *fpSource, *fpDest;
    fpSource = fopen(sourcePath, "r");
    fpDest = fopen(destPath, "w");

    if(fpSource == NULL || fpDest == NULL) {
        if(fpSource != NULL) fclose(fpSource);
        if(fpDest != NULL) fclose(fpDest);
        return 0;
    }
    
    char buffer[BUF_LEN];
    while(fgets(buffer, BUF_LEN, fpSource) != NULL) {
        int count = 0;
        int i = 0;

        while (buffer[i] != '\0') {
            if(buffer[i] == ' ') {
                count += 1;
            }
            i++;
        }
        fprintf(fpDest, "%d\n", count+1);
    }
    fclose(fpSource);
    fclose(fpDest);
    return 1;
}