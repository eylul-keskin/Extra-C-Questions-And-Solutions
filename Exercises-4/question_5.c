#include <stdio.h>

void removeAndCount(char *s, char c, int *cnt) {

    *cnt = 0; // we reset the value which was illustrated cnt
    char *p = s;

    while(*s != '\0') {
        if(*s == c) {
            (*cnt)++;
        } else {
            *p = *s;
            p++;
        }
        s++;
    }
    *p = '\0';
}

int main() {
    char string[] = "Programming";
    int cnt = 0;

    removeAndCount(string, 'c', &cnt);
    printf("%s", string);
    printf("%d", cnt);

    return 0;
}