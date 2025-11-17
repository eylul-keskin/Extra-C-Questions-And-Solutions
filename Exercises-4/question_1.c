
#include <stdio.h>

void change(char *p) {

    while (*p != '\0') 
    {
        if(*p >= 'a' && *p <= 'z') {
            *p -= 32;
        } else if(*p >= 'A' && *p <= 'Z') {
            *p +=32;
        }
        p++;
    }
    return;
}

int main() {
    char word[101];
    scanf("%s", word);

    change(word);
    printf("%s\n" , word);

    return 0;
}