#include <stdio.h>
int main()
{

	unsigned long a, b, c;
	printf("nhap a: ");
	scanf_s("%ld", &a);
	printf("nhap b: ");
	scanf_s("%ld", &b);
	printf("nhap c: ");
	scanf_s("%ld", &c);
	a = a + b + c;
	b = a - b - c;
	a = a - b - c;
	printf("a: %ld ", a);
	printf("b: %ld ", b);
	printf("c: %ld", c);
}