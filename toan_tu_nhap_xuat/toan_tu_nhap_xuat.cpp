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
ostream& operator<<(ostream& out,const PhanSo ps)
{
	return out << ps.layTu() << "/" << ps.layMau();
}
int main()
{
	PhanSo a;
	cin >> a;
	cout << a;
	return 0;
}