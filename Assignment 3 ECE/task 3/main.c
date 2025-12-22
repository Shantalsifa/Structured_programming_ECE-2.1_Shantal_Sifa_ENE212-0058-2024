#include <stdio.h>

int main() {
    // Objective: Learn pointer dereferencing and value modification using pointers

    int count = 10;
    int *pCount;

    pCount = &count;

    *pCount = 20;

    printf("Updated value of count: %d\n", count);

    return 0;
}
