#include "myfunction54.h"
int soluong(int n)
{
	int min = 10, k, dem = 1;
	while (n > 0)
	{
		k = n % 10;
		if (k == min)
		{
			dem++;
		}
		if (k < min)
		{
			min = k;
		}
		n = n / 10;
	}
	return dem;
}