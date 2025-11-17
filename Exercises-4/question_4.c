#include <stdio.h>

void count(char *s, int **p) {

    // NOTE: Pointer **res is used to modify the *res pointer in main.
    // **p (double dereference) accesses the value of the 'counter' variable in main.
    // Reset the counter value to zero.
    **p = 0;
    while (*s != '\0')
    {
        if(*s == 'c') {
            **p += 1;
        }
        s++;
    }
    return;
    
}
int main() {

    // char word[101 + sizeof(int)]; bu en güvenli yöntem ama daha basitini kullanalım.
    char word[105];

    // 1. The counter variable (the actual integer holding the count).
    int counter = 0;

    // 2. The pointer: Holds the memory address of the 'counter' variable.
    int *res = &counter;

    // Input Reading: Read up to 100 characters for buffer safety.
    if(scanf("%100s", word) != 1) { 
        // Hata durumunda çıkış
        return 1;
    }

    // We send the ADDRESS of the 'res' pointer (&res). 
    // The type of &res is int**, matching the function's parameter.
    count(word, &res);

    printf("/d\n", *res);

    return 0;  
}