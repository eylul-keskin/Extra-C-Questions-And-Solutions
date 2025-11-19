#include <stdio.h>

int question1(char *path1, char *path2, int *isEqual) {

    FILE *fp1, *fp2;
    char ch1, ch2;

    fp1 = fopen(path1, "r");
    fp2 = fopen(path2, "r");

    if(fp1 == NULL || fp2 == NULL) {
        perror("Dosya acilmadi");
        
        if(fp1 != NULL) fclose(fp1);
        if(fp2 != NULL) fclose(fp2);
        return 0;
    }

    *isEqual = 1;

    while (1)
    {
        ch1 = fgetc(fp1);
        ch2 = fgetc(fp2);

        if(ch1 != ch2) {
            *isEqual = 0;
            break;
        }
        if(ch1 == EOF) {
            break;
        }
    }   
    fclose(fp1);
    fclose(fp2);
    return 1;
}