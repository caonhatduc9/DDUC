#include"phieuMuonTraSach.h"
#include<string.h>
#include<iostream>
using namespace std;
// nhap thong tin phieu muon sach
void nhapPhieuMuon(char maSoMuon[][25], char ISBNSachMuon[][50], int ngayMuon[100], int thangMuon[100], int namMuon[100], int soLuong[], int &dem,int &n)
{
	dem = 0,n = 0;
		while (true)
		{
			if (n >= 100)
				cout << "Khong du bo nho!!";
			else
				while (n < 100)
				{
					// Nhap ma doc gia:
					cin.ignore(1);
					cout<<"\n +)Nhap ma doc gia muon sach: ";
					gets_s(maSoMuon[n]);
					cout<<" +)Nhap ngay muon sach: ";
					cin >> ngayMuon[n];
					cout << " +)Nhap thang muon sach: ";
					cin >> thangMuon[n];
					cout<<" +)Nhap nam muon sach: ";
					cin >> namMuon[n];
					cout<<" +)Nhap so luong sach doc gia muon: ";
					cin >> soLuong[n];
					cin.ignore(1);
					for (int i = 0; i < soLuong[n]; i++)
					{

						cout << "Nhap ISBN cua quyen sach thu " << i + 1 << " ";
						gets_s(ISBNSachMuon[i]);
						dem++;
					}
					++n;
					break;
				}
			break;
		}
	}

	
int soNgayTrongThang(int thang, int nam)
{
	switch (thang)
	{
	case 2:
		if ((nam % 4 == 0 && nam % 400 != 0) || nam % 400 == 0)
			return 29;
		return 28;
	case 4: case 6: case 9: case 11:
		return 30;
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
	default:
		return 0;
	}
	return -1;
}
int khoangCachNgay(int ngay1, int thang1, int nam1, int ngay2, int thang2, int nam2)
{
	int soNgay1, soNgay2;

	soNgay1 = ngay1; /* bắt đầu từ ngày và cộng số ngày của các tháng trước đó */
	for (int i = 1; i < thang1; i++)
		soNgay1 += soNgayTrongThang(i, nam1);

	soNgay2 = ngay2; /* bắt đầu từ ngày và cộng số ngày của các tháng trước đó */
	for (int i = 1; i < thang2; i++)
		soNgay2 += soNgayTrongThang(i, nam2);

	int soNgayN1N2 = 0;

	
	for (int i = nam1; i < nam2; i++)
		soNgayN1N2 = soNgayN1N2 + 365 + soNgayTrongThang(2, i) - 28;
	int khoangCach = soNgay2 - soNgay1 + soNgayN1N2;
	return khoangCach;
}

/*-------------Ham Tinh Thoi Gian Tra Sach Du Kien-------------*/
	// nhan vao ngay thang nam muon
// tra ra ngay tra du kien 

void thoiGianTraDuKien(int ngayMuon[], int thangMuon[], int namMuon[], int ngayTra[], int thangTra[], int namTra[], int n)
{
	if (ngayMuon[n - 1] <= soNgayTrongThang(thangMuon[n - 1], namMuon[n - 1]) - 6)
	{
		ngayTra[n-1] = ngayMuon[n-1] + 6;
		thangTra[n - 1] = thangMuon[n - 1];
		namTra[n - 1] = namMuon[n - 1];
	}
	else
	{
		if (thangMuon[n - 1] < 12)
		{
			ngayTra[n - 1] = ngayMuon[n - 1] + 6 - soNgayTrongThang(thangMuon[n - 1], namMuon[n - 1]);
			thangTra[n - 1]++;
		}
		else	if (thangMuon[n - 1] == 12)
		{
			ngayTra[n - 1] = ngayMuon[n - 1] + 6 - soNgayTrongThang(thangMuon[n - 1], namMuon[n - 1]);
			thangTra[n - 1] = 1;
			namTra[n - 1]++;
		}
	}
}
/*Ham Xuat Thong Tin Phieu Muon Sach	*/
void xuatPhieuMuon(int n,int soLuong[],char maSoMuon[][25],
	char ISBNSachMuon[][50], int ngayMuon[], int thangMuon[], int namMuon[], int ngayTra[], int thangTra[], int namTra[])
	{
		cout << "\n**************************************** PHIEU MUON SACH CUA DOC GIA **************************************************\n";
		cout << "* +Ma so doc gia muon sach: ";
		puts(maSoMuon[n - 1]);
		cout << "* +Thoi diem muon sach cua do gia ma so " << maSoMuon[n - 1] << " la: " << ngayMuon[n - 1] << "/" << thangMuon[n - 1] << "/" << namMuon[n - 1] << endl;
		cout << "* +Thoi diem tra sach du kien cua do gia ma so " << maSoMuon[n - 1] << " la: " << ngayTra[n - 1] << "/" << thangTra[n - 1] << "/" << namTra[n - 1];
		cout << "\n* +Danh sach ISBN cac sach duoc muon la:\n";
		for (int j = 0; j < soLuong[n - 1]; j++)
		{
			cout << "*\t +)ISBN cua quyen sach thu " << j + 1 << " la: ";
			puts(ISBNSachMuon[j]);
		}
		cout << "\n************************************************************************************************************************";
		cout << "\n------------------------------------------------------------------------------------------------------------------------";
		cout<<"\n| LUU Y: ";
		cout << "\n|- Doc gia tre han tra sach(7 ngay ke tu ngay muon sach) cho thu vien se phat 5000VND/1ngaytre.";
		cout<<"\n|- Neu mat sach se phai boi thuong 200%%  gia tri cua sach.\n";
	}

	/*Ham Nhap Thong Tin Cho Phieu Tra Sach*/	
void nhapPhieuTra(int n, int checkSach[100], int soLuong[], char maSoMuon[][25], char ISBNSachMuon[100][50], int& h, char maSoTra[][25], int ngayTraTT[], int thangTraTT[], int namTraTT[])
{
	while (1 < 2)
	{
		while (h < 100)
		{

			// Nhap ma doc gia tra sach:
			cin.ignore(1);
			cout << "\n +)Nhap ma doc gia tra sach: ";
			gets_s(maSoTra[h]);

			// Nhap thoi diem tra sach thuc te:
			cout << "\t+Nhap ngay tra sach thuc te : ";
			cin >> ngayTraTT[h];
			cout << "\t+Nhap thang tra sach thuc te : ";
			cin >> thangTraTT[h];
			cout << "\t+Nhap nam tra sach thuc te : ";
			cin >> namTraTT[h];
			for (int i = 0; i < n; i++)
			{
				int j;
				for (j = 0; j < soLuong[i]; j++)
				{
					cout << "nhap 1 neu quyen sach co ISBN " << ISBNSachMuon[j] << " bi mat" << " neu khong bi mat nhap 0\t";
					cin >> checkSach[j];
					cout << endl;
				}
			}
			h++;
			break;
		}
		break;
	}
}
	
	/*-------------Ham Tinh Tien Phat Khi Tra Sach Tre-------------*/
// nhan vao ham khoang cach ngay
	// tra ra so tien phat
int tinhTienPhat(int n,int ngayTra[], int thangTra[], int namTra[], int ngayTraTT[], int thangTraTT[], int namTraTT[])
	{
		int soTien = 0;
		int khoangCach = khoangCachNgay(ngayTra[n-1], thangTra[n-1], namTra[n-1], ngayTraTT[n-1], thangTraTT[n-1], namTraTT[n-1]);
		if (khoangCach > 0)
		{
			soTien = khoangCach * 5000;
			return soTien;
		}
		return soTien;
	}



	
	/*Ham Xuat Thong Tin Phieu Tra Sach*/

	void xuatPhieuTra(int checkSach[100],int n,char maSoMuon[][25], char maSoTra[][25], int ngayMuon[], int thangMuon[], int namMuon[],  int ngayTra[], int thangTra[], int namTra[],
		int ngayTraTT[], int thangTraTT[], int namTraTT[], int soLuong[], char ISBNSachMuon[][50], int h,int giaSach[])
	{
		int check = 0;
		int flag = 0;
		for (int i = 0; i < n; i++)
		{
			if (strcmp(maSoMuon[i], maSoTra[h - 1]) == 0)
			{
				cout << "\n*************************************************** PHIEU TRA SACH CUA DOC GIA **************************************\n";
				cout << " +Ma so doc gia tra sach: ";
				puts(maSoMuon[i]);
				cout << " +Thoi diem muon sach cua do gia ma so " << maSoMuon[i] << " la: " << ngayMuon[i] << "/" << thangMuon[i] << "/" << namMuon[i];
				cout << "\n +Thoi diem tra sach du kien cua doc gia co ma so " << maSoMuon[i] << " la: " << ngayTra[i] << "/" << thangTra[i] << "/" << namTra[i];
				cout << "\n +Thoi diem tra sach thuc te cua doc gia co ma so " << maSoMuon[i] << " la: " << ngayTraTT[i] << "/" << thangTraTT[i] << "/" << namTraTT[i];
				cout << "\n Danh sach ISBN cac sach duoc muon la:\n";
				for (int j = 0; j < soLuong[i]; j++)
				{
					cout << "\t +)ISBN cua quyen sach thu " << j + 1 << " la: ";
					puts(ISBNSachMuon[j]);
					if (checkSach[j] == 1)
						cout << "< Do lam mat sach nen quy khach phai den 200% theo gia bia cua quyen sach co ISBN " << ISBNSachMuon[j] << "la: " << giaSach[j] << ">" << endl;
				}


				cout << " +)So tien phat khi tra sach tre la: " << tinhTienPhat(n, ngayTra, thangTra, namTra, ngayTraTT, thangTraTT, namTraTT) <<"VND"<< endl;
				cout << "==================================================================================================================\n";
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			cout << "Khong co thong tin doc gia tra sach!!";
	}

	