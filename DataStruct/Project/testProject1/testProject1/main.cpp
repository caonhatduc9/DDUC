#include<iostream>
#include<fstream>
using namespace std;
int main(int argc, char* argv[])
{
	int* a;
	int n;
	ifstream f;
	f.open("input.txt");
		f >> n;
		int i = 0;
	a = new int[n];
	while (!f.eof())
	{
		f >> a[i++];
	}
	f.close();
	cout << a[0] << a[1] << a[2] << a[3] << a[4];
	return 0;
}