#include "NhanVien.h"
#pragma once
class NVSanXuat : public NhanVien
{
private:
	int soSanPham;
public:
	void nhap();
	void xuat();
	float tinhLuong();
	NVSanXuat(string, string, int);
	NVSanXuat();
	~NVSanXuat();
};

