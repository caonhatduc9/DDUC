#include "myfunction70.h"
float sum(int n, float x)
{
	float T = x * (-1), M = 1, s = 0;
		int i = 1, j;
	while (i <= n)
	{
		T = T * x * x * (-1);
		j = 2 * i + 1;
		M = M * j * (j - 1);
		s = s + T / M;
		i++;
	}
	s = 1 - x + s;
	return s;
}