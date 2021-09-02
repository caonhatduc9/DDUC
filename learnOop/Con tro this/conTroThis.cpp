#include<iostream>
using namespace std;
//con tro this la tham chiueu den doi tuowng dang goi ham thanh phan
class phanSo
{
public:
	void intput();
	void output();
	phanSo rutGon();

private:
	int tu, mau;
};

void phanSo::intput()
{
	cout << "nhap tu: ";
	//cin >> tu;
	cin >> this->tu;
	cout << "nhap mau so: ";
	//cin >> mau;
	cin >> this->mau;
}

void phanSo::output()
{
	cout << this->tu << "/" << this->mau;
}
//cach 2 tra ve object hien tai
phanSo phanSo::rutGon() {
	int a, b;
	a = abs(this->tu);
	b = abs(this->mau);
	while(a != b)
	{
		if (a > b)
			a -= b;
		else b -= a;
	}
	this->tu /= a;
	this->mau /= a;
	return *this;
}
int main()
{
	phanSo ps;
	ps.intput();
	ps.rutGon();
	ps.output();
	return 0;
}