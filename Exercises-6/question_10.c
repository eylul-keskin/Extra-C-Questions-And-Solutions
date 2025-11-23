#include <stdio.h>

int question_10(char *filename, int givenID, float change) {
    FILE *fp;

    int ids[1000];
    char names[1000][50];
    int ages[1000];
    float balances[1000];

    int count = 0;
    fp = fopen(filename, "r+");

    if(fp == NULL) {
        return 0;
    }

    while(scanf(fp, "%d %s %d %f", &ids[count], names[count], &ages[count], &balances[count]) == 4) {

        if(ids[count] == givenID) {
            balances[count] += change;
        }
        count++;
    }
    rewind(fp);

    for(int i = 0 ; i < count ; i++) {
        fprintf(fp, "%d %s %d %f\n", ids[i], names[i], ages[i], balances[i]);
    }

    fclose(fp);
    return 1;
}