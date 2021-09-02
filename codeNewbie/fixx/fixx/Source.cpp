#include <stdio.h>
bool kiemtrauocso(int n);
int main()
{
	int n;
	printf("nhap vao mot so");
	scanf_s("%d", &n);
	
	if (kiemtrauocso(n))
		printf("%d la so nguyen to", n);
	else
		printf("%d khong la so nguyen to", n);
	
}
bool kiemtrauocso(int n)
{
	if (n < 2)
	{
		return false;
	}
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0)
			return 0;
	return true;
}