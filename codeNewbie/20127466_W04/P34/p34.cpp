// 20127466
// CAO NHAT DUC
// CLC07

// Test case 1
// Input: 5
// Output: 2.74

// Test case 2
// Input: 10
// Output: 3.68

// Test case 3
// Input: 7
// Output: 3.16

#include <stdio.h>
#include <math.h>
int main()
{
	int n, i = 1;
	float s = 0;
	printf("nhap n(n>0): ");
	scanf_s("%d", &n);
	while (i <= n)
	{
		s = sqrt(i + s);
		i++;
	}
	printf("ket qua: %.2f", s);
	return 0;
}