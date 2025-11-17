#include <stdio.h>
#include <stddef.h> // Necessary for using the NULL macro

char* find(char *s) {

    while (*s != '\0')
    {
        if(*s == 'c') {
            return s; // it returns the address, not the character's value
        }
        s++;
    }
    return NULL;
}
int main() {
    char word[101];

    // this prevents buffer overflow 
    if(scanf("%100s" , word) != 1) {
        return 1;
    }

    char *result_ptr = find(word);
    if(result_ptr != NULL) {
        printf("Karakter 'c' adreste bulundu: %p\n", result_ptr);
        printf("Bulunan karakter: %c\n", *result_ptr);
    } else {
        printf("Karakter 'c' bulunamadi.\n");
    }
    
    return 0;
}