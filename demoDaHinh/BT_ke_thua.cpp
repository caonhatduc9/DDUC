#include "NhanVien.h"
#include "NVVanPhong.h"
#include "NVSanXuat.h"
#include"congTy.h"
int main()
{
	congTy c;
	c.nhap();
	c.xuat();
	float tong = c.tinhTongLuong();
	return 0;
}