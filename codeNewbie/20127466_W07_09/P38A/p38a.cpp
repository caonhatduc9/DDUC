#include<iostream>
using namespace std;

int main()
{
	int ranka, rankb, s = 0, i;
	int n = 0, a[100];
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a[i];
	}
	cin >> ranka;
	cin >> rankb;
	for (i = ranka - 1; i <= rankb - 2; i++)
	{
		s += a[i];
	}
	cout << s;
}

