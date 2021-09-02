// 20127466
// CAO NHAT DUC
// CLC07

// Test case 1
// Input: 3,4
// Output: 10.05

// Test case 2
// Input: 3,7
// Output: 10.07

// Test case 3
// Input: 2,3
// Output: 3.76

#include <stdio.h>
int main()
{
	double x, s = 0, T = 1, M = 1;
	int n, i = 1, j = 1;
	printf("nhap x: ");
	scanf_s("%lf", &x);
	printf("nhap n: ");
	scanf_s("%d", &n);
	while (i <= n)
	{
		T = T * x * x;
		j = 2 * i;
		M = M * j * (j - 1);
		s = s + T / M;
		i++;
	}
	s = s + 1;
	printf("ket qua: %.2lf", s);
	return 0;
}