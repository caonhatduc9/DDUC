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
	printf("nhap a,b,c: \n");
	scanf_s("%f %f %f", &a, &b, &c);
	delta = b * b - 4 * a * c;
	if (delta < 0)
	{
		printf("pt vo nghiem");
	}
	else
	{
		if (delta == 0)
		{
			x1 = x2 = 1.0*-b / 2 / a;
			if (x1 > 0)
			{
				printf("pt co nghiem %f, %f", sqrt(x1), -sqrt(x1));
			}
			else
				if (x1 == 0)
				{			printf("pt co nghiem 0");
				}
				if (x1 < 0)
				{
					printf("ptvn");
				}
			}
		else
		{
			x1 = 1.0*(-b + sqrt(delta)) / 2.0 / a;
			x2 = 1.0*(-b - sqrt(delta)) / 2.0 / a;
			if (x1 >= 0 && x2 >= 0)
			{
				printf("pt co nghiem %f, %f, %f, %f"), sqrt(x1), -sqrt(x1), sqrt(x2), -sqrt(x2);
			}
			if (x1 < 0 && x2 < 0)
			{
				printf("ptvn");
			}
			if (x1 < 0 && x2 >= 0)
			{
				printf("pt co nghiem %f, %f", sqrt(x2), -sqrt(x2));
			}
			if (x1 >= 0 && x2 < 0)
			{
				printf("pt co nghiem %f, %f", sqrt(x1), -sqrt(x1));
			}
		}
	}
}