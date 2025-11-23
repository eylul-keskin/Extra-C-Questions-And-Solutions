#include <stdio.h>

int question8(char *sourcePath, char *destPath) {
    int id;
    char name[50];
    int age;
    float balance;

    FILE *fpSource, *fpDest;
    fpSource = fopen(sourcePath, "r");
    fpDest = fopen(destPath, "w");

     if(fpSource == NULL || fpDest == NULL) {
        if(fpSource != NULL) fclose(fpSource);
        if(fpDest != NULL) fclose(fpDest);
        return 0;
    }

    while ((fscanf(fpSource, "%d %s %d %f", &id, name, &age, &balance)) == 4) {
        if(age < 25) {
            fprintf(fpDest, "Account balance of customer %d (%s) is %f\n", id, name, balance);
        }
    }
    fclose(fpSource);
    fclose(fpDest);
    return 1;
}