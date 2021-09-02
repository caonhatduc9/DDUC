// 20127466
// Cao Nhat Duc
// CLC07

// test case 1
// input: 
// output: 

// test case 2
// input: 
// output: 

// test case 3
// input: 
// output: 

#include <stdio.h>
#include <math.h>
int main()
{
	float a, b, c, x1, x2, delta;
	printf("nhap a,b,c: ");
	scanf_s("%f %f %f", &a, &b, &c);
	if (a == 0)
	{
		if (b == 0)
		{
			printf("pt vo nghiem");
		}
		else
		{
			if (a == 0)
			{
				if (b == 0)
				{
					printf("pt co vo so nghiem");
				}
				else
				{
					printf("pt vo nghiem");
				}
			}
			else
			{
				x1 = -b / a;
				printf("nghiem la: %.2f", x1);
			}
		}
	}
	else
	{
		delta = b * b - 4 * a * c;
		if (delta < 0)
		{
			printf("pt vo nghiem");
		}
		else
		{
			if (delta == 0)
			{
				x1 = x2 = -b / 2 / a;
				printf("phuong trinh co nghiem kep x1=x2=%.2f", x1);
			}
			else
			{
				x1 = (-b + sqrt(delta)) / 2.0 / a;
				x2 = (-b - sqrt(delta)) / 2.0 / a;
				printf("phuong trinh co 2 nghiem phan biet x1=%.2f, x2=%.2f", x1, x2);
			}
		}
	}
}