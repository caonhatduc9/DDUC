#include "myfunction66.h"
float sum(int n)
{
	int i = 1;
	float T = -1, s = 0, M = 0;
	while (i <= n)
	{
		T = T * (-1);
		M = M + i;
		s = s + T / M;
		i++;
	}
	return s;
}