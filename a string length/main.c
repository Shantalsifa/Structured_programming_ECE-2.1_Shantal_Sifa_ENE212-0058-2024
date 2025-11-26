#include <stdio.h>

int main(){
const double PI=3.142;
float radius,surface_area;

printf("Enter the radius of the sphere: ");
scanf("%f", &radius);

surface_area=4*PI*radius*radius;

printf("Surface_area of the sphere=%f\n",surface_area);

return 0;

}

