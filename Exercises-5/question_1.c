#include <stdio.h>

/**
 * Swaps the values of two integers pointed to by x and y.
 * Constraint: Only 1 local variable allowed.
 */
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

/**
 * Checks if the array A is sorted in ascending order.
 * result is returned via the pointer *p (1 for sorted, 0 for unsorted).
 * * Logic: Iterates using pointer arithmetic since loop variables are forbidden.
 */
void isSorted(int *A, int *p) {
    *p = 1; // Assume sorted initially
    
    // Check current and next element until the stop character (0) is reached
    while(*A != 0 && *(A+1) != 0) {
        if(*A > *(A+1)) {
            *p = 0; // Found an element greater than the next one
            return;
        }
        A++; // Move pointer to the next element
    }
}

/**
 * Finds the index of the minimum value in the remaining subarray.
 * The index is stored in *p.
 * * Logic: Uses (cursor - A) to calculate index via pointer subtraction.
 */
void indexOfMin(int *A, int *p) {
    int *cursor = A; // Pointer to traverse the array
    *p = 0;          // Initialize index of min as 0 (relative to A)

    while (*cursor != 0) {
        // Compare current element (*cursor) with the current minimum (*(A + *p))
        // *(A + *p) is equivalent to A[min_index]
        if(*cursor < *(A + *p)) {
            // Calculate index using pointer difference
            *p = (int) (cursor - A);
        }
        cursor++;
    }
}

int main(int argc, char *argv[]) {
    int A[1000];    // Main storage array
    int *p = A;     // Pointer for traversal
    int temp;       // Single temporary variable for input/logic/swapping

    // --- LOOP 1: INPUT ---
    // Reads positive integers until 0 is entered.
    while(1) {
        scanf("%d", &temp);

        if(temp == 0) {
            *p = 0; // Add stop character
            break;
        }
        *p = temp;
        p++;
    }

    // Check if the array is already sorted
    // 'temp' is reused to store the boolean result (1 or 0)
    isSorted(A, &temp);
    
    // --- LOOP 2: SORTING ---
    // Implements Selection Sort logic (finding min and swapping)
    // This was required despite the assignment title "Bubble Sort" description implies Selection Sort logic.
    if(temp == 0) {
        p = A; // Reset pointer to start

        while (*p != 0)
        {
            // Find index of min element in subarray starting at p
            // 'temp' is reused to store the index
            indexOfMin(p, &temp);
            
            // Swap current element with the minimum element found
            // (p + temp) points to the address of the minimum element
            swap(p, p + temp);

            p++; // Move to next element
        }
    }

    // --- LOOP 3: OUTPUT ---
    p = A; // Reset pointer to start
    while (*p != 0)
    {
        printf("%d ", *p);
        p++;
    }
    
    return 0;
}