#include"thongKe.h"
#include<iostream>
using namespace std;
// thong ke sach theo the loai
//nhan vao soluong sach , the loai ,so quyen sach
//xuat ra so luong sach theo the loai
void thongKeSachTheoTheLoai(int soLuongSach, char theLoai[][30], int soQuyenSach[])
{
	int dem = 0;
	for (int i = 0; i < soLuongSach; i++)
	{
		dem = 0;
		for (int j = 0; j < soLuongSach; j++)
		{
			if (strcmp(theLoai[i], theLoai[j]) == 0)
			{
				if (i <= j)//Dieu kien de chay bien dem
					dem = dem + soQuyenSach[j];
				else
					break;
			}
		}
		if (dem != 0)
			cout << "The loai " << theLoai[i] << " co so luong sach la: " << dem << endl;
	}
}

//thong ke so luong sach
// nhan vao so luong sach, so quyen sach
// tra ve dem
int  thongKeSLSach(int soLuongSach, int soQuyenSach[])
	{
		int dem = 0;
		for (int i = 0; i < soLuongSach; i++)
		{
			dem = dem + soQuyenSach[i];
		}
		return dem;
	}
/*thong ke doc gia theo gioi tinh
nhan vao so luong doc gia , gioi tinh
xuat ra so doc gia theo gioi tinh
*/
void thongKeDGTheoGioiTinh(int soLuongDG,int gioiTinhDG[])
{
	int demnam = 0, demnu = 0;
	for (int i = 0; i < soLuongDG; i++)
	{
		if (gioiTinhDG[i] == 1)
			demnam++;
		else
			demnu++;
	}
	cout << "Co " << demnam << " so luong doc gia nam\n";
	cout << "Co " << demnu << " so luong doc gia nu\n";
}
/*
nhan vao so phieu sach muon,ngaythangnam du kien tra,ngaythangnam tra thuc te
tra ve dem
*/
int  thongKeDGTreHan(int n,int ngayTra[], int thangTra[], int namTra[], int ngayTraTT[], int thangTraTT[], int namTraTT[])
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (ngayTraTT[i] > ngayTra[i] || thangTraTT[i] > thangTra[i] || namTraTT[i] > namTra[i])
			dem++;
	}
	return dem;
}