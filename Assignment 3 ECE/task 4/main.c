#include <stdio.h>

int main() {
    // Objective: Perform arithmetic operations using pointer dereferencing

    int num1 = 5, num2 = 7;
    int *ptr1, *ptr2;

    ptr1 = &num1;
    ptr2 = &num2;

    int sum = *ptr1 + *ptr2;

    printf("Task 4: Add Two Numbers Using Pointers\n");
    printf("Sum of %d and %d = %d\n", num1, num2, sum);

    return 0;
}
