// 20127466
// CAO NHAT DUC
// CLC07

// Test case 1
// Input: 3
// Output: 0.75

// Test case 2
// Input: 5
// Output: 0.83

// Test case 3
// Input: 21
// Output: 0.95

#include <stdio.h>
int main()
{
	int i = 1, n;
	double s = 0;
	printf("nhap n: ");
	scanf_s("%d", &n);
	while (i <= n)
	{
		s = s + 1.0*1 / i / (i + 1);
		i++;
	}
	printf("ket qua: %.2lf", s);
	return 0;
}