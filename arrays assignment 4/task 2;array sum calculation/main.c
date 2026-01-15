#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n;
  int sum = 0;
    printf("Input the number of elements to be stored in the array : ");
    scanf("%d", &n);

  int arr[n];
    printf("Input %d elements in the array :\n", n);

  for (int i = 0; i < n; i++)
   {
    printf("element - %d : ", i);
    scanf("%d", &arr[i]);

    sum = sum + arr[i];
   }

    printf("Sum of all elements stored in the array is : %d", sum);
    return 0;
}
