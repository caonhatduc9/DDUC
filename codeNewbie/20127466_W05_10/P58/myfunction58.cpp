#include "myfunction58.h"
bool kiemtra(int n)
{
	int cuoi, kecuoi, k;
	cuoi = n % 10;
	k = n / 10;
	while (k > 0)
	{
		kecuoi = k % 10;
		k = k / 10;
		if (kecuoi > cuoi)
		{
			return 0;
			break;
		}
		else
			cuoi = kecuoi;
	}
	return 1;
}

	