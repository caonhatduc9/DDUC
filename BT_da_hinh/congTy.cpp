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
		NhanVien* temp = new NVVanPhong;
		if (choice == 1) 
			temp = new NVVanPhong;
		if (choice == 2)
			temp = new NVQuanLy;
		if (choice == 3) 
			temp = new NVSanXuat;
		if (choice == 4)
			break;
		temp->nhap();
		DSNhanVien.push_back(temp);

	} while (choice != 4);

}
void congTy::xuat() {
	for (int i = 0; i < DSNhanVien.size(); i++)
	{
		cout << endl;
		DSNhanVien[i]->xuat();
	}
	
}
float congTy::tinhTongLuong() {
	float sum = 0;
	for (int i = 0; i < DSNhanVien.size(); i++)
		sum += DSNhanVien[i]->tinhLuong();
	return sum;
}
void congTy::search(string name) {
	for (int i = 0; i < DSNhanVien.size(); i++)
		if (name == DSNhanVien[i]->getName())
			DSNhanVien[i]->xuat();
}
congTy::congTy() {}
congTy::~congTy() {}