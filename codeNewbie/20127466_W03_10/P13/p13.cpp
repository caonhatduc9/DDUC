// 20127466
// Cao Nhat Duc
// CLC07

// test case 1
// input: 1
// output: 1 khong phai nam nhuan

// test case 2
// input: 4
// output: 4 la nam nhuan

// test case 3
// input: 2020
// output: 2020 la nam nhuan

#include <stdio.h>
int main()
{
	long n;
	printf("nhap vao nam: ");
	scanf_s("%ld", &n);
	if ((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0))
	{
		printf("%ld la nam nhuan", n);
	}
	else
	{
		printf("%ld khong phai nam nhuan", n);
}
}