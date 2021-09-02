// 20127466
// Cao Nhat Duc
// CLC07

// test case 1
// input: 1500000 2 1
// output:  1530000.000000

// test case 2
// input: 1500000 2 3
// output:  1591812.000000

// test case 3
// input: 1500000 1 7
// output: 1608203.028161

#include <stdio.h>
#include <math.h>
int main()
{
	double tien, s;
	int rate, month;
	printf("nhap so tien gui: ");
	scanf_s("%lf", &tien);
	printf("nhap lai xuat: ");
	scanf_s("%d", &rate);
	printf("thoi gian(thang): ");
	scanf_s("%d", &month);
	if (0 < rate < 100 || month < 1 || tien < 0)
	{
		tien = tien * pow(1 + 1.0*rate/100, month);
		printf("Tong so tien lai: %lf", tien);
	}
	else
	{
		printf("nhap lai");
	}
}