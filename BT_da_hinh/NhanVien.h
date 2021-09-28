#include<iostream>
using namespace std;
#include<string>
#pragma once
class NhanVien
{
protected:
	string hoTen, ngaySinh;
	float luong, luongCoBan;
public:
	string getName() {
		return hoTen;
	}
	//dung ao thay vi thuan ao vi lop con co the truy cap tro nguoc lai phuong
	//thuc cua lop cha
	virtual void nhap();
	virtual	void xuat();
	virtual float tinhLuong() = 0;
	NhanVien();
	~NhanVien();
};

