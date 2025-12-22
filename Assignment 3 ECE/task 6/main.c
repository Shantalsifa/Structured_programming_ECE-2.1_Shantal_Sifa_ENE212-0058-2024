#include <stdio.h>

// Function to increment by value
void incrementByValue(int x) {
    x = x + 1;
    printf("Inside incrementByValue: x = %d\n", x);
}

// Function to increment by reference
void incrementByReference(int *x) {
    *x = *x + 1;
    printf("Inside incrementByReference: x = %d\n", *x);
}

int main() {

    // Objective: Understand difference between pass by value and pass by reference
    int value = 10;

    printf("Task 6: Pass by Value vs Pass by Reference\n");
    printf("Original value: %d\n", value);

    // Call function using pass by value
    incrementByValue(value);
    printf("After incrementByValue (pass by value): %d\n", value);

    // Call function using pass by reference
    incrementByReference(&value);
    printf("After incrementByReference (pass by reference): %d\n", value);

    return 0;
}
