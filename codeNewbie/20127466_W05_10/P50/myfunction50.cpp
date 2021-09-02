#include "myfunction50.h"
int daoso(int n)
{
	int T = 0, k;
	while (n > 0)
	{
		k = n % 10;
		T = 10 * T + k;
		n = n / 10;
	}
	return T;
}
