#include <stdio.h>
#include <string.h>

int question7(char *sourcePath, char *destPath, char *oldWord, char *newWord) {

    FILE *fpSource, *fpDest;
    char buffer[100];

    fpSource = fopen(sourcePath, "r");
    fpDest = fopen(destPath, "w");


    if(fpSource == NULL || fpDest == NULL) {
        if(fpSource != NULL) fclose(fpSource);
        if(fpDest != NULL) fclose(fpDest);
        return 0;
    }

    while ((fscanf(fpSource, "%s", buffer)) != EOF) {
        if(strcmp(buffer, oldWord) == 0) {
            fprintf(fpDest, "%s ", newWord);
        } else {
            fprintf(fpDest, "%s ", buffer);
        }
    }
    
    fclose(fpSource);
    fclose(fpDest);
    return 1;
}