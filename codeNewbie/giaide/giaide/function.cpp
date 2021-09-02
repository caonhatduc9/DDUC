#include"function.h"
int SoNumber(int x)
{
	int k = 0;
	while (x > 0)
	{
		k++;
		x = x / 10;
	}
	return k;
}
void speakNumber(int k)
{
	if (k == 0)
		cout << "khong";
	else if (k == 1)
		cout << "mot";
	else if (k == 2)
		cout << "hai";
	else if (k == 3)
		cout << "ba";
	else if (k == 4)
		cout << "bon";
	else if (k == 5)
		cout << "nam";
	else if (k == 6)
		cout <<" sau";
	else if (k == 7)
		cout <<" bay";
	else if (k == 8)
		cout << "tam";
	else if (k == 9)
		cout <<" chin";

}
int luyThua1(int x, int count)
{
	while (x > 0)
	{
		x = x / 10;
		count++;
	}
	return count;
}

int luyThua2(int n)
{
	int lt = 1;
	for (int i = 0; i < n; i++)
	{
		lt = lt * 10;
	}
	return lt;
}
