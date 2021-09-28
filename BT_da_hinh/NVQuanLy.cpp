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
	cout << "He so luong: " << heSo << endl;
	cout << "thuong: " << thuong << endl;
}
float NVQuanLy::tinhLuong() {
	luong = luongCoBan * heSo + thuong;
	return luong;
}
NVQuanLy::NVQuanLy() {}
NVQuanLy::~NVQuanLy() {}
