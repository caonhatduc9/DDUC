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
	string showName(){
		return name;
	}
	void rename(string name) {
		this->name = name;
	}
};

int main()
{//ham khoir tao sao chep chi copy chu khong tham chieu
	HOCSINH hs1(1, "Duc"), hs2;
	hs2 = HOCSINH(hs1);
	cout << hs2.showName() << "\t" << hs1.showName() << endl;
	hs1.rename("Cao Duc");
	cout << hs2.showName() << "\t" << hs1.showName() << endl;
	cout << &hs1 << " " << &hs2;
}