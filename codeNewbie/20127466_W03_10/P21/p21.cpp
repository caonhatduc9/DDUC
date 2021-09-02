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
	double n;
	printf("nhap so: ");
	scanf_s("%lf", &n);
	double k = n - int(n);
	
	if (k >= 0.75)
	{
		k = int(n) + 1;
	}
	else {
		k = int(n) + 0.5;
	}
	printf("%lf duoc lam tron thanh %lf ", n, k);
}