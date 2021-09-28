#include "NhanVien.h"
void NhanVien::nhap() {
	cin.ignore();
	cout << "nhap ho va ten: ";
	getline(cin, hoTen);
	cout << "nhap ngay sinh: ";
	getline(cin, ngaySinh);
}
NhanVien::NhanVien()
{
	luongCoBan = 200000;
}
void NhanVien::xuat() {
	cout << "ha va ten: " << hoTen << endl;
	cout << "ngay sinh: " << ngaySinh << endl;
	cout << "luong co ban: " << luongCoBan << endl;
}
NhanVien::~NhanVien() {}