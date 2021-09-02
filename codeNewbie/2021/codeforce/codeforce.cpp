#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int a, b, n;
	int x;
	float check;
	cin >> a >> b >> n;
	if (a < 0 || b < 0)
	{
		a = -a;
		b = -b;
	}
	check = log(b / a) / log(n);
	x = log(b / a) / log(n);
	//cout << check << "   " << x;
	if (check == (int)check)
		
	cout << x;
	else
		cout << "no slution";
	return 0;
}