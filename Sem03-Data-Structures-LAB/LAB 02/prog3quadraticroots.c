#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float a, b, c;
float D;
float root1, root2;
float real, img;

void getData()
{
	printf("Please enter the value of a,b,c \n");
	scanf("%f%f%f", &a, &b, &c);
}
void findRoots()
{
	if (D > 0)
	{
		printf("The roots are real and distinct \n");
		root1 = (-b + pow(D, 0.5)) / (2.0 * a);
		root2 = (-b - pow(D, 0.5)) / (2.0 * a);
	}

	if (D == 0)
	{
		printf("The roots are real and equal \n");
		root1 = root2 = (-b) / (2.0 * a);
	}

	if (D < 0)
	{
		printf("The roots are complex and distinct \n");
		real = (-b) / (2.0 * a);
		img = (pow(-D, 0.5)) / (2.0 * a);
	}
}

void printRoots()
{
	if (D >= 0)
	{
		printf("root1= %f root2=%f \n", root1, root2);
	}
	if (D < 0)
	{
		printf("The roots are root1= %f+i%f and root2=%f-i%f \n", real, img, real, img);
	}
}
void main()
{

	getData();
	D = (b * b) - (4 * a * c);
	findRoots();
	printRoots();
}