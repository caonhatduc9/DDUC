#include <stdio.h>
int main()
{
	unsigned long a, b;
	printf("nhap a: ");
	scanf_s("%ld", &a);
	printf("nhap b: ");
	scanf_s("%ld", &b);
	a = a + b;
	b = a - b;
	a = a - b;
	printf("a: %ld\n", a);
	printf("b: %ld", b);
}