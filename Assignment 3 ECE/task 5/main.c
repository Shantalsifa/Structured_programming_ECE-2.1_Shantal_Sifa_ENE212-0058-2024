#include <stdio.h>

void swapNumbers(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    // Objective: Understand pass by reference using pointers and functions
    int a = 15, b = 25;

    printf("Task 5: Swap Two Numbers Using Pointers\n");
    printf("Before swapping: a = %d, b = %d\n", a, b);

    // Call function by passing addresses of a and b
    swapNumbers(&a, &b);

    printf("After swapping: a = %d, b = %d\n", a, b);

    return 0;
}
