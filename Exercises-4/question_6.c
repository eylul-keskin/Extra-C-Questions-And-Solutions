#include <stdio.h>

int compare(char *s1, char *s2) {

    while(*s1 != '\0' && *s2 != '\0') {

        if(*s1 < *s2) {
            return -1;
        } else if(*s1 > *s2) {
            return 1;
        } 
        s1++;
        s2++;
    }
    if (*s1 == '\0' && *s2 == '\0') {
        return 0;
    }
    else if(*s1 != 0 && *s2 == '\0') {
        return 1;
    } else if(*s2 != 0 && *s1 == '\0') {
        return -1;
    }
    return 0;
}

int main() {

    char s1[] = "AAAAB";
    char s2[] = "AAAC";

    int res = compare(s1, s2);
    return res;
}