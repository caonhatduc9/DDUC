#include "NhanVien.h"
#pragma once
class NVVanPhong : public NhanVien
{
private:
	int soNgayLamViec;
	float troCap;
public:
	void nhap();
	void xuat();
	float tinhLuong();
	NVVanPhong(string, string, int, float);
	NVVanPhong();
	~NVVanPhong();
};

