#include<iostream>
#include<string>
using namespace std;
class PHANSO {
private:
	int tu, mau;
public:
	PHANSO()
	{
		tu =  0;
		mau = 1;
	}
};
class HOCSINH {
private:
	int mssv;
	string name;
public:
	//cu phap
	HOCSINH() {}
	HOCSINH(int id, string ten)
	{
		mssv = id;
		name = ten;
	}
	HOCSINH(const HOCSINH &hs)
	{
		name = hs.name;
	}
};

int main()
{
	HOCSINH hs1(1, "Duc"), hs2;
	hs2 = HOCSINH(hs1);

}