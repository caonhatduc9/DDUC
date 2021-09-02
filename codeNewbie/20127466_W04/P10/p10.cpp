// 20127466
// CAO NHAT DUC
// CLC07

// Test case 1
// Input: 2,3
// Output: 8

// Test case 2
// Input: 9,10
// Output: 3486784401

// Test case 3
// Input: 3,7
// Output: 2187

#include <stdio.h>
int main()
{
	double x, p = 1;
	int n, i = 1;
	printf("nhap x: ");
	scanf_s("%lf", &x);
	printf("nhap n: ");
	scanf_s("%d", &n);
	while (i <= n)
	{
		p = p * x;
		i++;
	}
	printf("ket qua: %.2lf", p);
	return 0;
}