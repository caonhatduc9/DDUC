#include<iostream>
#include<string>
using namespace std;
class PHANSO {
private:
	int tu, mau;
public:
	PHANSO(int t, int m)
	{
		tu = t;
		mau = m;
	}
	//hoac
	PHANSO(int t)
	{
		tu = t;
		mau = 1;
	}
};
int main()
{
	PHANSO ps(1);

}