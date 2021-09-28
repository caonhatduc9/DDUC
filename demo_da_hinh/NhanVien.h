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
	void nhap();
	void xuat();
	NhanVien(string, string);
	NhanVien();
	~NhanVien();
};

