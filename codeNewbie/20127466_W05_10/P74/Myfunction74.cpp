#include "myfunction74.h"
int songaymax(int m, int y)
{
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		return 31;
	else
		if (m == 2)
		{
			if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
				return 29;
			return 28;
		}
	return 30;
}