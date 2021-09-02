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
	int a, b, c, d, max, min;
	printf("nhap a,b,c,d khac nhau: ");
	scanf_s("%d%d%d%d", &a, &b, &c, &d);
	if (a > b)
	{
		max = a;
	}
	else 
	{
		max = b;
	}
	if (max > c)
	{
		max = max;
	}
	else 
	{
		max = c;
	}
	if (max > d)
	{
		max = max;
	}
	else
	{ 
		max = d;
	}

	if (a > b)
	{
		min = b;
	}
	else
	{
		min = a;
	}
	if (min > c)
	{
		min = c;
	}
	else
	{
		min = min;
	}
	if (min > d)
	{
		min = d;
	}
	else
	{
		min = min;
	}

	printf("%d %d", max,min);
}