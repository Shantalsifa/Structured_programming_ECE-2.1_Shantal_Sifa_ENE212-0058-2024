#include <stdio.h>

int main(){

int num1,num2;
//take two numbers as input
printf("enter the first number");
scanf("%i",&num1);

printf("enter the second number");
scanf("%i",&num2);

//perform the arithmetic operations
printf("Addition:%i + %i=%i\n",num1,num2,num1 + num2);
printf("Subtraction:%i - %i=%i\n",num1,num2,num1 - num2);
printf("Multiplication:%i * %i=%i\n",num1,num2,num1 * num2);
printf("Division:%i / %i=%i\n",num1,num2,num1 / num2);
printf("Modulus:%i % %i=%i\n",num1,num2,num1 % num2);
return 0;
}
