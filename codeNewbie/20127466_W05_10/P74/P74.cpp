//CAO NHAT DUC
//20127466
//CLC07

// TEST CASE 1
// input: 2 3 2020
// output: 62

// TEST CASE 2
// input: 2 3 2019
// output: 61

// TEST CASE 3
// input: 31 12 2020
// output: 366

#include "myfunction74.h"
#include <iostream>
using namespace std;
int main()
{
	int d, m, y, songay = 0, stt;
	cout << "nhap ngay/thang/nam:";
	cin >> d >> m >> y;
	if (d > songaymax(m, y))
	{
		cout << "nhap lai";
	}
	else
	{
		songay = d;
		for (int i = 1; i <= m - 1; i++)
		{
			songay = songay + songaymax(i, y);
		}
		cout << songay;
		return 0;
	}
}