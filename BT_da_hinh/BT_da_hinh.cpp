
#include "congTy.h"
#include<vector>
int main()
{
	congTy c;
	c.nhap();
	c.xuat();
	cout << "\n\nLUONG: " << (size_t)c.tinhTongLuong();
	cout << "\n\t\tnhap ten nhan vien can tim kiem: ";
	c.search("cao duc");
	return 0;
}