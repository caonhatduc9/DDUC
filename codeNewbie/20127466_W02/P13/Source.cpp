#include <stdio.h>
#include <math.h>
int main()
{
	double edge1, edge2, edge3, s, p;
	printf("nhap do dai ba canh\n");
	scanf_s("%lf%lf%lf", &edge1, &edge2, &edge3);
	p = edge1 + edge2 + edge3;
	s = sqrt((p / 2) * (p / 2 - edge1) * (p / 2 - edge2) * (p / 2 - edge3));
	printf("chu v: %0.2lf  dien tich: %0.2lf", p, s);
}