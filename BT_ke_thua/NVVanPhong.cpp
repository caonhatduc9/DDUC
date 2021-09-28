#include "NVVanPhong.h"
NVVanPhong::NVVanPhong(string hoTen, string ngaySinh, int soNgay, float troCap) 
{
	soNgayLamViec = soNgay;
	this->troCap = troCap;
}
void NVVanPhong::nhap()
{
	NhanVien::nhap();
	cout << "so ngay lam viec: ";
	cin >> soNgayLamViec;
	cout << "tro cap: ";
	cin >> troCap;
}
void NVVanPhong::xuat() {
	NhanVien::xuat();
	cout << "so ngay lam viec: " << soNgayLamViec << endl;
	cout << "tro cap: " << troCap << endl;
}
float NVVanPhong::tinhLuong() {
	luong = luongCoBan + troCap + soNgayLamViec * 100000;
	return luong;
}
NVVanPhong::NVVanPhong() {};
NVVanPhong::~NVVanPhong() {};
