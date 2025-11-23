#include <stdio.h>
#include <string.h>
#define BUF_LEN 500

int removeWord(const char *source, const char *destination, char *str) {

    FILE *fpSource, *fpDestination;
    fpSource = fopen(source, "r"),
    fpDestination = fopen(destination, "w");

    if(fpSource == NULL || fpDestination == NULL) {
        if(fpSource != NULL) fclose(fpSource);
        if(fpDestination != NULL) fclose(fpDestination);
        return 0;
    }

    char line[BUF_LEN]; // tüm satırı tutacak dizi

    while (fgets(line, BUF_LEN, fpSource) != NULL) {
        char *ptr = line;
        char word[BUF_LEN];
        while (scanf)
        {
            /* code */
        }
        
        if(strcmp(temp, str) == 0) {

        }
    }
    
}