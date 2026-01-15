#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, value, pos;
    printf("Input the size of array : ");
    scanf("%d", &n);

  int arr[n + 1];
    printf("Input %d elements in the array:\n", n);

  for (int i = 0; i < n; i++)
    {
      printf("element - %d : ", i);
      scanf("%d", &arr[i]);
    }

  printf("Input the value to be inserted : ");
  scanf("%d", &value);

  printf("Input the Position, where the value to be inserted : ");
  scanf("%d", &pos);

  for (int i = n; i > pos; i--)
    {
       arr[i] = arr[i - 1];
    }
  arr[pos] = value;

  printf("After Insert the element the new list is : ");

  for (int i = 0; i <= n; i++)
    {
       printf("%d ", arr[i]);
    }

  return 0;
}
