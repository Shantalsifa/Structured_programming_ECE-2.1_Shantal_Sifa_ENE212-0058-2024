#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n;
    printf("Input the number of elements to be stored in the array : ");
    scanf("%d", &n);

  int arr[n];
    printf("Input %d elements in the array :\n", n);

  for (int i = 0; i < n; i++)
    {
    printf("element - %d : ", i);
    scanf("%d", &arr[i]);
    }

  int max = arr[0], min = arr[0];

  for (int i = 1; i < n; i++)
    {
   if (arr[i] > max) max = arr[i];
   if (arr[i] < min) min = arr[i];
    }

    printf("Maximum element is : %d\n", max);
    printf("Minimum element is : %d", min);

  return 0;
}
