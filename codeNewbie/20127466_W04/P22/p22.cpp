// 20127466
// CAO NHAT DUC
// CLC07

// Test case 1
// Input: 6
// Output: 36

// Test case 2
// Input: 20
// Output: 8000

// Test case 3
// Input: 12
// Output: 1728

#include <stdio.h>
int main()
{
	int n, i = 1, p = 1;
	printf("nhap n: ");
	scanf_s("%d", &n);
	while(i <= n)
	{
		if (n % i == 0)
		{
			p = p * i;
		}
		i++;
	}
	printf("ket qua: %d", p);
	return 0;
}