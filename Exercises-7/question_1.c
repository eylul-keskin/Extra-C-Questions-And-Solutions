#include <stdio.h>

int question_1(const char *file, int senderID, int receiverID, float sentMoney) {
    FILE *fp;
    fp = fopen(file, "r+");

    if(fp == NULL) { return 0; }
    while (fgets(fp))
    {
        /* code */
    }
    
}