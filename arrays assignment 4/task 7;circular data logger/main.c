#include <stdio.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int index = 0;
int count = 0;

void insert(int value)
 {
    buffer[index] = value;
    index = (index + 1) % BUFFER_SIZE;

    if (count < BUFFER_SIZE)
        {
        count++;
        }
  }

void printBuffer()
{
    if (count == 0)
    {
      printf("Buffer is empty.\n");
      return;
    }

    int start = (index + BUFFER_SIZE - count) % BUFFER_SIZE;

    printf("Buffer (oldest → newest): ");

    for (int i = 0; i < count; i++)
        {
        int pos = (start + i) % BUFFER_SIZE;  // Wrap around
        printf("%d ", buffer[pos]);
        }
    printf("\n");
}

int main()
 {
    int value;

    printf("Circular Data Logger (BUFFER_SIZE = %d)\n", BUFFER_SIZE);

    while (1)
        {
        printf("Enter a value (-1 to stop): ");
        scanf("%d", &value);

        if (value == -1)
            {
            break;
            }

        insert(value);
        printBuffer();
        }

    return 0;
}
