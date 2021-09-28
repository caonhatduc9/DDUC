#include "NVQuanLy.h"

void NVQuanLy::nhap()
{
	NhanVien::nhap();
	cout << "nhap he so: ";
	cin >> heSo;
	cout << "nhap tien thuong: ";
	cin >> thuong;
}
void NVQuanLy::xuat() {
	NhanVien::xuat();
	cout << "NV quan ly:\n";
	cout << "He so luong: " << heSo << endl;
	cout << "thuong: " << thuong << endl;
}
float NVQuanLy::tinhLuong() {
	luong = luongCoBan * heSo + thuong;
	return luong;
}
NVQuanLy::NVQuanLy(string hoTen, string ngaySinh, float heSo, float thuong) : NhanVien(hoTen, ngaySinh)
{

	this->heSo = heSo;
	this->thuong = thuong;
}

NVQuanLy::NVQuanLy() {}
NVQuanLy::~NVQuanLy() {}
