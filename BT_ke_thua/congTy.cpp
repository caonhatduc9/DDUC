#include "congTy.h"

void congTy::nhap() {
	int choice;
	do {
		cout << "\n===MENU===" << endl;
		cout << "1 - nhap nv van phong" << endl;
		cout << "2 - nhap nhan vien quan ly:" << endl; 
		cout << "3 - nhap nhan vien san xuat" << endl;
		cout << "4 - thoat" << endl;
		cin >> choice;
		if (choice == 1) {
			NVVanPhong vp;
			vp.nhap();
			VP.push_back(vp);
		}
		if (choice == 2) {
			NVQuanLy ql;
			ql.nhap();
			QL.push_back(ql);
		}
		if (choice == 3) {
			NVSanXuat sx;
			sx.nhap();
			SX.push_back(sx);
		}
	}while(choice != 4);
	
}
void congTy::xuat() {
	cout << "\n nhan vien quan ly\n";
	for (int i = 0; i < QL.size(); i++)
		QL[i].xuat();
	cout << "\n nhan vien van phong\n";
	for (int i = 0; i < VP.size(); i++)
		VP[i].xuat();
	cout << "\n nhan vien san xuat\n";
	for (int i = 0; i < SX.size(); i++)
		SX[i].xuat();
}
float congTy::tinhTongLuong() {
	float sum = 0;
	for (int i = 0; i < QL.size(); i++)
		sum += QL[i].tinhLuong();
	for (int i = 0; i < VP.size(); i++)
		sum += VP[i].tinhLuong();
	for (int i = 0; i < SX.size(); i++)
		sum += SX[i].tinhLuong();
	return sum;
}
void congTy::search(string name) {
	for (int i = 0; i < QL.size(); i++)
		if (QL[i].getName() == name)
			QL[i].xuat();
	for (int i = 0; i < VP.size(); i++)
		if (VP[i].getName() == name)
			VP[i].xuat();
	for (int i = 0; i < SX.size(); i++)
		if (SX[i].getName() == name)
			SX[i].xuat();
}
congTy::congTy() {}
congTy::~congTy() {}