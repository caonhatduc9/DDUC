#include "NVSanXuat.h"
void NVSanXuat::nhap() {
	NhanVien::nhap();
	cout << "nhap so san pham: ";
	cin >> soSanPham;
}
void NVSanXuat::xuat() {
	NhanVien::xuat();
	cout << "so san pham: " << soSanPham << endl;
}
float NVSanXuat::tinhLuong() {
	luong = soSanPham * 2000 + luongCoBan;
	return luong;
}
NVSanXuat::NVSanXuat(string hoTen, string ngaySinh, int soSanPham) :NhanVien(hoTen, ngaySinh)
{
	this->soSanPham = soSanPham;
}
NVSanXuat::NVSanXuat() {}
NVSanXuat::~NVSanXuat() {}