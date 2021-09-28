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
NhanVien::NhanVien(string hoTen, string ngaySinh) {
	this->hoTen = hoTen;
	this->ngaySinh = ngaySinh;	
}
void NhanVien::xuat() {
	cout << "day la class nhan vien\n";
	cout << "ha va ten: " << hoTen << endl;
	cout << "ngay sinh: " << ngaySinh << endl;
	cout << "luong co ban: " << luongCoBan << endl;
}
NhanVien::~NhanVien() {}
