#include<iostream>
using namespace std;

int* oddNumbers(int* a, int lena, int* b, int lenb)
{
	int lenc = 0, idx = 0;
		for (int i = 0; i < lena; i++)
			if (a[i] % 2 != 0)
				lenc++;
	for (int i = 0; i < lenb; i++)
		if (a[i] % 2 != 0)
			lenc++;
	int* c = new int[lenc];
	for (int i = 0; i < lena; i++)
		if (a[i] % 2 != 0)
			c[idx++] = a[i];
	for (int i = 0; i < lenb; i++)
		if (b[i] % 2 != 0)
			c[idx++] = b[i];
	return c;
}
//tinh tong 1.3.5+3.5.7+...
int Sum(int n)
{
	if (n == 1)
		return 15;
	else return n * (n+2) * (n + 4) + Sum(n - 2);
}
int main()
{
	/*int* a = { new int[5]{1,2,3,4,5} };
	int* b = { new int[3]{7,5,4} };
	int* c = NULL;
	c = oddNumbers(a, 5, b, 3);
	for (int i = 0; i < 5; i++)
		cout << c[i];*/
	cout << Sum(1);
	return 0;
}