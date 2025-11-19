#include <stdio.h>

/**
 * Calculates the length of a string using pointer arithmetic.
 * Constraint: No loop variables allowed.
 */
void findLength(char *s, int *p) {
    *p = 0; // Initialize length counter
    while (*s != '\0') {
        (*p)++; // Increment value at p
        s++;    // Move string pointer forward
    }
}

/**
 * Validates if the string consists only of lowercase English alphabets.
 * Sets *p to 1 if valid, 0 otherwise.
 */
void isAllLowerChars(char *s, int *p) {
    *p = 1; // Assume valid initially
    while (*s != '\0') {
        if(*s < 'a' || *s > 'z') {
            *p = 0; // Invalid character found
            return;
        }
        s++;
    }
}

/**
 * Searches for the first occurrence of char 'c' in string 's'.
 * Saves the ADDRESS of the found character into **p.
 * If not found, sets *p to NULL.
 */
void findCharFirstLoc(char *s, char c, char **p) {
    while (*s != '\0')
    {
        if(*s == c) {
            *p = s; // Save the address of the found character
            return;
        } 
        s++;
    }
    *p = NULL; // Character not found
}

int main(int argc, char *argv[]) {
    char s[800], c; // Input buffer and delimiter
    int flag;       // Reused integer for validation results and length
    char *p;        // Iterator pointer
    char *foundLoc; // Pointer to hold the address of the found delimiter

    // --- LOOP 1: INPUT & VALIDATION ---
    // Continues until both string and char are lowercase.
    while (1) {
        // Read inputs
        // Note: scanf writes directly into 's', overwriting previous invalid inputs if any.
        scanf("%s %c", s, &c); 

        // Check constraints
        isAllLowerChars(s, &flag);
        
        // flag == 1 means string is valid.
        // (c >= 'a' && c <= 'z') checks if the char is valid.
        if (flag == 1 && (c >= 'a' && c <= 'z')) {
            break; // Inputs are valid, proceed to logic.
        }
    }

    // --- LOOP 2: TOKENIZING STRATEGY ---
    // Algorithm: Replace the delimiter with '\0' to "cut" the string in memory.
    p = s; // Start from the beginning
    while (1) {
        // Find the address of the next delimiter
        findCharFirstLoc(p, c, &foundLoc);

        // If no more delimiters, break loop
        if (foundLoc == NULL) {
            break;
        }

        // CRITICAL STEP for O(1) Space Complexity:
        // Replace the delimiter with Null Terminator.
        // This effectively ends the current string token right here.
        *foundLoc = '\0';
        
        // Calculate length of the current token
        findLength(p, &flag); 
        printf("%d %s\n", flag, p); // Print Length and Token

        // Move the pointer just after the delimiter for the next iteration
        p = foundLoc + 1; 
    }

    // Print the remaining part of the string (after the last delimiter)
    findLength(p, &flag);
    printf("%d %s\n", flag, p);

    return 0;
}