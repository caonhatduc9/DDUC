#include"Myfunction.h"
int timk(int n)
{
	int i = 0, s = 0;
	while (s + i < n)
	{
		i++;
		s = s + i;
	}
	return i;
}