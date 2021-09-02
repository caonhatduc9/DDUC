// 20127466
// CAO NHAT DUC
// CLC07

// Test case 1
// Input: 6
// Output: YES

// Test case 2
// Input: 10
// Output: NO

// Test case 3
// Input: 123456
// Output: NO
#include <stdio.h>
int main()
{
	int n, i = 1, s = 0;
	printf("nhap n: ");
	scanf_s("%d", &n);
	while (i < n)
	{
		if (n % i == 0)
		{
			s = s + i;
		}
		i++;
	}
			if (s == n)
			{
				printf("YES");
			}
			else
			{
				printf("NO");
			}
	return 0;
}