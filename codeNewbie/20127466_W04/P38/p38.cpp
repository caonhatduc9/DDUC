// 20127466
// CAO NHAT DUC
// CLC07

// Test case 1
// Input: 5
// Output: 1.36

// Test case 2
// Input: 10
// Output: 1.25

// Test case 3
// Input: 3
// Output: 1.45

#include <stdio.h>
// 20127466
// CAO NHAT DUC
// CLC07

// Test case 1
// Input: 5
// Output: 1.36

// Test case 2
// Input: 123
// Output: 1.04

// Test case 3
// Input: 64
// Output: 1.07

#include <math.h>
int main()
{
	int n, i = 1;
	float s = 0;
	printf("nhap n(n>0): ");
	scanf_s("%d", &n);
	while (i <= n)
	{
		s = pow((i + s) * 1.0, 1.0 / (i + 1));
		i++;
	}
	printf("ke qua %.2f", s);
	return 0;
}