#include<iostream>
using namespace std;
#include"NhanVien.h"
#include"NVQuanLy.h"
#include"NVSanXuat.h"
#include"NVVanPhong.h"
#include<vector>
int main() {
	//vung chon kieu
	vector<NhanVien*> nv;
	NVQuanLy ql("Cao Duc", "10072002", 2, 100000);
	NVSanXuat sx("Thao Quyen", "23122002", 99);
	NVVanPhong vp("cao Duc 2", "10072002", 2, 9999);
	NhanVien* temp = new NVQuanLy("Cao Duc", "10072002", 2, 100000);
	nv.push_back(temp);
	((NVQuanLy*)nv[0])->xuat();
	return 0;
}