#include <stdio.h>
#include <math.h>
int main()
{
	unsigned long e, r;
	double pi = 3.14, s;
	printf("nhap chieu dai canh tam giac ");
	scanf_s("%ld", &e);
	printf("nhap ban kinh duong tron ");
	scanf_s("%ld", &r);
	s = 3 * sqrt(3) * e / 4 + pi * r * r / 2;
	printf("dien tich can tinh la: %lf", s);
}