#include <stdio.h>
int main()
{
	unsigned long percent, quota;
	double s;
	printf("percent: ");
	scanf_s("%ld", &percent);
	printf("quota ");
	scanf_s("%ld", &quota);
	s = quota / percent * 100;
	printf("so tien mua hang %.2lf", s);
}
