#include <stdio.h>
#include <math.h>
#include <conio.h>
void main()
{
	double x, y1, y2, pi = 3.14, e = 2.71;
	printf("nhap vao so thuc khong am x ");
	scanf_s("%lf", &x);
	y1 = 4 * (x * x + 10 * x * sqrt(x) + 3 * x + 1);
	y2 = (sin(pi * x * x) + sqrt(x * x + 1)) / (pow(e, 2 * x) + cos(x * pi / 4));
	printf("y1 la %.10lf, y2 la %.10lf", y1, y2);
	_getch();
}