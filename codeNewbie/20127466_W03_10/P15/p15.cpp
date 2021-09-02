// 20127466
// Cao Nhat Duc
// CLC07

// test case 1
// input: 1 10 2019
// output: ngay tiep theo 2/10/2019

// test case 2
// input: 31 10 2019
// output: ngay tiep theo 1/11/2019

// test case 3
// input: 31 12 2019
// output: ngay tiep theo 1/1/2020

#include <stdio.h>
int songaytrongthang(int ngay, int thang);
int main()
{
	int d, m, songay;
	long y;
	printf("nhap ngay thang nam\n");
	scanf_s("%d%d%ld", &d, &m, &y);
	songay = songaytrongthang(m, y);
		if (d < songay)
		{
			d++;
		}
		else if (m < 12)
		{
			d = 1;
			m++;
		}
		else 
		{
			d = 1;
			m = 1;
			y++;
		}
	printf("ngay tiep theo %d/%d/%ld", d, m, y);
}
int songaytrongthang(int thang, int nam)
{
	int ngaytrongthang;
	switch (thang)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		ngaytrongthang = 31;
			break;
	case 4:
	case 6:
	case 9:
	case 11:
		ngaytrongthang = 30;
		break;
	case 2:
		if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0))
		{
			ngaytrongthang = 29;
		}
		else
		{
			ngaytrongthang = 28;
		}
	}
	return ngaytrongthang;
}