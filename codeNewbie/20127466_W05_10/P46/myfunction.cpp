#include "myfunction.h"
int demso(int n)
{
	int dem = 0, k, i;
	while (n > 0)
	{
		k = n % 10;
		if ((k % 2) != 0)
		{
			dem++;
		}
		n = n / 10;
	}
	return dem;
}