#include <stdio.h>

void findAddress(char *s, char **p) {

    /* The variable last_c_address inside main is already a pointer (char*). 
       Since we must send its address to the function, the function parameter receives it as a double pointer (char**). 
       This is necessary for the function to permanently update the original pointer's value*/
    char *last_occurrence = NULL;

    while(*s != '\0') {
        if(*s == 'c') {
            *p = s;
        }
        s++;
    }
    *p = last_occurrence;
    return;
}

int main() {
    char word[101];
    char *last_c_address = NULL;
    
    if (scanf("%100s", word) != 1) {
        return 1;
    }

    findAddress(word, &last_c_address);
    
    if (last_c_address != NULL) {
        printf("%p\n", (void *)last_c_address);
        printf("%c\n", *last_c_address); 
    } else {
        printf("Karakter 'c' bulunamadi.\n");
    }

    return 0;
}

// last_c_address --> char*(type) --> address of 'c' or NULL(value held) --> The variable we want to change(role)
// &last_c_address --> char**(type) --> the address of the last_c_address variable(value held) --> The value sent to the function(role) 
// p --> char**(type) --> Receives the address of last_c_address(value held) --> Allows access to the pointer in main(role)
// *p --> char*(type) --> Allows us to change the value inside the last_c_address variable.(value held) --> The assignment target inside the function(role)