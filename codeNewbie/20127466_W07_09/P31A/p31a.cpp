#include<iostream>
using namespace std;
int main()
{
	int a[100], n = 0, i, j, k, l, check = 0;
	cin >> n;
	for ( l = 0; l < n; l++)
	{
		cin >> a[l];
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (j != i)
			{
				for (k = 0; k < n; k++)
				{
					if (k != j && k != i && (a[k] == a[j] + a[i]) && a[k] >= a[j] && a[j] >= a[i])
					{
						k++ ; i++; j++;
						cout << k << " " << j << " " << i << " ";
						check++;
						
					}
				if (check != 0)
						break;
				}
			if (check != 0)
					break;
			}
		}
	}
	if (check == 0)
		cout << "-1";
}