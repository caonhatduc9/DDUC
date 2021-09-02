#include<iostream>
using namespace std;
int main()
{
	int a[1000], n = 0, d, dem = 0;
	cin >> n;
	cin >> d;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (abs(a[i] - a[j]) <= d && i != j)
				dem++;
		}
	}
	cout << dem;
	return 0;
}