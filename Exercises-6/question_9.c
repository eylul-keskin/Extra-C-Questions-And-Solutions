#include <stdio.h>

int question_9(char *filename, int id, char *name, int age, float balance) {
    FILE *fp;

    fp = fopen(filename, "a");

    if(fp == NULL) {
        return 0;
    }

    fprintf(fp, "%d %s %d %f\n", id, name, age, balance);

    fclose(fp);
    return 1;
}