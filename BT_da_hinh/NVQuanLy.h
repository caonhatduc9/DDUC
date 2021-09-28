#include "NhanVien.h"
#pragma once
class NVQuanLy : public NhanVien
{
private:
	float heSo, thuong;
public:
	void nhap();
	void xuat();
	float tinhLuong();
	NVQuanLy();
	~NVQuanLy();
};

