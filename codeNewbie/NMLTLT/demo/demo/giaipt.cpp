#include <iostream>
using namespace std;
int main()
{
	int n;
	cout << "nhap n";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= 2 * n - 1; j++)
		{
			if (j >= n - i && j <= n + i)
			{
				if (j <= n)
					cout << j;
				else
					cout << 2 * n - j;
			}
			else
				cout << " ";
		}
		cout << "\n";
	}
	return 0;
}