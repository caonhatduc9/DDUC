/*
* protected: chi lop con moi truy cap duoc
* ham ban co the truy cap dc car public proteced private
*/

#include<iostream>
using namespace std;
class Nguoi {
protected:
	int namSinh;
	string ten;
public:
	Nguoi() {}
	Nguoi(int nam, string ten)
	{
		this->namSinh = nam;
		this->ten = ten;
	}
	void An()
	{
		cout << ten << " an 2 kg gao";
	}
	void show()
	{
		cout << "\nNguoi: " << "ho va ten: " << ten;
		cout << endl << "nam sinh: " << namSinh;

	}
};
//kieu ke thua public
class SinhVien : public Nguoi 
{
 protected:
	string id;
public:
	SinhVien() {}
	SinhVien(int nam, string ten, string id) : Nguoi(nam, ten) {
		this->id = id;
	}
	void show()
	{
		cout << "\nNguoi: \n" << "ho va ten: " << ten;
		cout << endl << "nam sinh: " << namSinh;
		cout << endl << id;
		SinhVien::An();
	}
};
class NuSinh : public SinhVien
{
	float diem;
public:
	NuSinh(	int namSinh, string ten, string id,float diem):SinhVien(namSinh,ten,id) {
		this->diem = diem;
	}
	void show()
	{
		cout << "\nNguoi: \n" << "ho va ten: " << ten;
		cout << endl << "nam sinh: " << namSinh;
		cout << endl << id;
		SinhVien::An();
	}
};
int main()
{
	NuSinh s(2002, "Tran Thao Quyen", "20127305", 10);
	s.show();
	return 0;
}