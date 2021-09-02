// 20127466
// CAO NHAT DUC
// CLC07

// Test case 1
// Input: 6
// Output: 3

// Test case 2
// Input: 100
// Output: 125

// Test case 3
// Input: 8
// Output: 1

#include <stdio.h>
int main()
{
	int n, i = 1, p = 1;
	 printf("nhap n: ");
	scanf_s("%d", &n);
	while(i <= n)
	{
		if (n % i == 0 && i % 2 != 0)
		{
			p = p * i;
		}
		i++;
	}
	printf("ket qua: %ld", p);
	return 0;
}