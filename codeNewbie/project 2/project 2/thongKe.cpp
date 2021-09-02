#include"thongKe.h"
#include"quanLyDG.h"
#include"quanLySach.h"
#include"phieuMuonTra.h"
#include<iostream>
using namespace std;
// thong ke sach theo the loai
//nhan vao soluong sach , the loai ,so quyen sach
//xuat ra so luong sach theo the loai
void thongKeSachTheoTheLoai(book b[],int m)
{
	int dem = 0;
	for (int i = 0; i < m; i++)
	{
		dem = 0;
		for (int j = 0; j < m; j++)
		{
			if (strcmp(b[i].theLoai, b[j].theLoai) == 0)
			{
				if (i <= j)
					dem = dem + b[j].soQuyenSach;
				else
					break;
			}
		}
		if (dem != 0)
			cout << "The loai " << b[i].theLoai << " co so luong sach la: " << dem << endl;
	}
}

//thong ke so luong sach
// nhan vao so luong sach, so quyen sach
// tra ve dem
int  thongKeSLSach(book b[],int m)
{
	int dem = 0;
	for (int i = 0; i < m; i++)
	{
		dem = dem + b[i].soQuyenSach;
	}
	return dem;
}
/*thong ke doc gia theo gioi tinh
nhan vao so luong doc gia , gioi tinh
xuat ra so doc gia theo gioi tinh
*/
void thongKeDGTheoGioiTinh(DG d[],int n)
{
	int demnam = 0, demnu = 0;
	for (int i = 0; i < n; i++)
	{
		if (d[i].gioiTinhDG == 1)
			demnam++;
		else
			demnu++;
	}
	cout << "Co " << demnam << " doc gia nam\n";
	cout << "Co " << demnu << " luong doc gia nu\n";
}
/*
nhan vao so phieu sach muon,ngaythangnam du kien tra,ngaythangnam tra thuc te
tra ve dem
*/
int  thongKeDGTreHan(int x, P1 p1[], P2 p2[])
{
	int dem = 0;
	for (int i = 0; i < x; i++)
	{
		if (p2[i].ngayTraTT > p1[i].ngayTra || p2[i].thangTraTT > p1[i].thangTra || p2[i].namTraTT > p1[i].namTra)
			dem++;
	}
	return dem;
}