// 20127466
// CAO NHAT DUC
// CLC07

// Test case 1
// Input: 2,3
// Output: 170

// Test case 2
// Input: 4,5
// Output: 4473924

// Test case 3
// Input: 4,3
// Output: 17476

#include <stdio.h>
int main()
{
	double x, p , s = 0;
	int n, i = 1;
	printf("nhap x: ");
	scanf_s("%lf", &x);
	printf("nhap n: ");
	scanf_s("%d", &n);
	p = x;
	while (i <= n)
	{
		p = p * x * x;
		s = s + p;
		i++;
	}
	s = s + x;                                      
	printf("ket qua: %lf", s);
	return 0;
}