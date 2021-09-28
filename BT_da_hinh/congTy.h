#include "NVQuanLy.h"
#include "NVSanXuat.h"
#include "NVVanPhong.h"
#include<vector>
#include<fstream>	
#include<iostream>
using namespace std;
#pragma once
class congTy
{
private:
	vector<NVQuanLy> QL;
	vector<NVVanPhong> VP;
	vector<NVSanXuat> SX;
	vector<NhanVien*> DSNhanVien;

public:
	void nhap();
	void xuat();
	float tinhTongLuong();
	void search(string);
	congTy();
	~congTy();
};

