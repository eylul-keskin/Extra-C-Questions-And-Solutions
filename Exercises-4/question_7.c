#include <stdio.h>

int palindrome(char *s) {

    char *p = s;

    while(*p != '\0') {
        p++;
    }

    if( p > s) {
        // The purpose is to move the pointer back one position from the null terminator ('\0') 
        // to point to the string's last actual character.
        p--; 
    }

    while(s < p) { // index olarak düşündüğüm için böyle dedim ancak ** olarak mı düşünmeliydim neden düşünmedim
       
        if(*p != *s) {
            return 0;
        } 
        p--;
        s++;
    }

    return 1;
}

int main() {
    char str[] = "";

    int res = palindrome(str);
    return res;
}