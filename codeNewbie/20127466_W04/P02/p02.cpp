// 20127466
// CAO NHAT DUC
// CLC07

// Test case 1
// Input: 5
// Output: 55

// Test case 2
// Input: 10
// Output: 385

// Test case 3
// Input: 7
// Output: 140

#include <stdio.h>
int main()
{
	int s = 0, n, i = 1;
	printf("nhap n: ");
	scanf_s("%d", &n);
	while (i <= n)
	{
		s = s + i * i;
		i++;
	}
	printf("ket qua: %d", s);
	return 0;
}