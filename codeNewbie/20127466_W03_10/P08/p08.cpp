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
int main()
{
	float a, b, x;
	printf("nhap a,b: ");
	scanf_s("%f%f", &a, &b);
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
		x = -b / a;
		printf("nghiem la: %.2f", x);
	}




	 
}