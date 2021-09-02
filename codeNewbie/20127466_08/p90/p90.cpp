/*
CAOP NHAT DUC
CLC07
20127466

Test case 1
input 5
output 420

Test case 2
input 6
output 756

Test case 3
input 7
output 1260

*/

#include<iostream>
using namespace std;
int main()
{
	int n, s=0;
	cout << "nhap n: ";
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int t = i;
		t *= (i + 1);
		t *= (i + 2);
		s += t;
	}
	cout << s;
}