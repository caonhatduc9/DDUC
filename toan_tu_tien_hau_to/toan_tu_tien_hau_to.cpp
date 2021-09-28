#include<iostream>
using namespace std;
class PhanSo {
private:
	int tuSo, mauSo;
public:
	PhanSo() {
		tuSo = 0;
		mauSo = 1;
	}
	PhanSo(int tu, int mau) {
		this->mauSo = mau;
		this->tuSo = tu;
	}
	int layTu()const
	{
		return this->tuSo;
	}
	int layMau()const
	{
		return this->mauSo;
	}
	void thayDoiTu(int t) {
		this->tuSo = t;
	}
	void thayDoiMau(int m)
	{
		this->mauSo = m;
	}
	//istream& operator>>(istream&, PhanSo&);
	friend PhanSo operator+(int, PhanSo);
	PhanSo operator+(int);
	//tien to
	PhanSo &operator++()
	{
		tuSo = mauSo + 1;
		return *this;
	}
	//hau to
	PhanSo& operator++(int) {
		PhanSo temp = *this;
		++* this;
		return temp;
	}
};
//nonmember function
istream& operator>>(istream& in, PhanSo& ps)
{
	int a, b;
	cout << "nhap tu: ";
	in >> a;
	cout << endl << "nhap mau: ";
	in >> b;
	ps = PhanSo(a, b);
	return in;
}
//co the khong can de const voi cac kieu du lieu int,float...
//con doi voi cac kieu du lieu struct con tro nen de const
ostream& operator<<(ostream& out, const PhanSo ps)
{
	return out << ps.layTu() << "/" << ps.layMau();
}

PhanSo PhanSo::operator+(int k)
{
	PhanSo temp;
	temp.tuSo = k * mauSo + tuSo;
	temp.mauSo = mauSo;
	return temp;
}
PhanSo operator+(int a, PhanSo ps)
{
	PhanSo temp;
	temp.tuSo = a * ps.mauSo + ps.tuSo;
	temp.mauSo = ps.mauSo;
	return temp;
}
int main()
{
	PhanSo a(1, 2), b(3, 4);
	b = ++a;
	cout << a << b;
	return 0;
}