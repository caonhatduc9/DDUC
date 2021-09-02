#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int a[100], n = 0, min;
	int k = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	min = abs(a[0] - a[1]);
	for (int i = 0; i <= n - 2; i++)
	{
		if (abs(a[i] - a[i + 1]) < min)
		{
			min = abs(a[i] - a[i + 1]);
			k = i+1;
		}
	}
	if (abs(a[n - 1] - a[0]) > min)
		cout << k << " " << k + 1;
		else
	cout << n << " " << "1";
	return 0;
}
