// 20127466
// Cao Nhat Duc
// CLC07

// test case 1
// input: 2 3
// output: 28

// test case 2
// input: 12 2020
// output: 31

// test case 3
// input: 2 2020 
// output: 29

#include <stdio.h>
int main()
{
	long y;
	int m;
	printf("nhap thang: ");
	scanf_s("%d", &m);
	printf("nhap mam: ");
	scanf_s("%ld", &y);
	switch (m)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		printf(" thang %d co 31 ngay", m);
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		printf(" thang %d co 30 ngay", m);
		break;
	case 2:
		if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
		{
			printf(" thang %d nam %d co 29 ngay", m, y);
		}
		else
		{
			printf(" thang %d nam %d co 28 ngay", m, y);
		}
	}
}