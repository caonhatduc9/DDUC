#include <stdio.h>
bool kiemtrauocso(int n);
int main()
{
	int n;
	printf("nhap vao mot so");
	scanf_s("%d", &n);
	if (kiemtrauocso(n) == true);
	{
		printf("n la so nguyen to");
	}
	else
	{
		printf("n khong la so nguyen to");
	}
}
bool kiemtrauocso(int n)
{
	if (n < 2)
	{
		return false;
	}
	else
	{
		if (n == 2)
		{
			return true;
		}
		else
		{
			if (n % 2 == 0)
			{
				return false;
			}
			else
			{
				for (int i = 2; i < n; i++)
				{
					if (n % i == 0)
					{
						return false;
				}
			}
		}
	}
}
return true;
}