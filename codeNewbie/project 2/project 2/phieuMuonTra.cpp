#include"phieuMuonTra.h"
#include"quanLySach.h"
#include<string.h>
#include<fstream>
#include<iostream>
using namespace std;

// nhap thong tin phieu muon sach
void nhapPhieuMuon(P1 &p, int& dem,char ISBNSachMuon[100][50])
{
				
				
				cout << "\n +)Nhap ma doc gia muon sach: ";
				cin >> p.maSoMuon;
		     	cout << " +)Nhap ngay muon sach: ";
				cin >> p.ngayMuon;
				cout << " +)Nhap thang muon sach: ";
				cin >> p.thangMuon;
				cout << " +)Nhap nam muon sach: ";
				cin >> p.namMuon;
				cout << " +)Nhap so luong sach doc gia muon: ";
				cin >> p.soLuong;
				cin.ignore(1);
				for (int i = 0; i < p.soLuong; i++)
				{
					cout << "Nhap ISBN cua quyen sach thu " << i + 1 << "    ";
					gets_s(ISBNSachMuon[i]);
					dem++;
				}
}

void nhapListPhieuMuon(P1 listPhieuMuon[], int& dem, int& x, char ISBNSachMuon[100][50])
{
	
	while (true)
	{
		if (x >= 100)
			cout << "Khong du bo nho!!";
		else
		{
			while (x < 100)
			{
				nhapPhieuMuon(listPhieuMuon[x], dem, ISBNSachMuon);
				x++;
				break;
			}
			break;
		}	
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

	soNgay1 = ngay1; //bắt đầu từ ngày và cộng số ngày của các tháng trước đó 
	for (int i = 1; i < thang1; i++)
		soNgay1 += soNgayTrongThang(i, nam1);

	soNgay2 = ngay2; // bắt đầu từ ngày và cộng số ngày của các tháng trước đó 
	for (int i = 1; i < thang2; i++)
		soNgay2 += soNgayTrongThang(i, nam2);

	int soNgayN1N2 = 0;


	for (int i = nam1; i < nam2; i++)
		soNgayN1N2 = soNgayN1N2 + 365 + soNgayTrongThang(2, i) - 28;
	int khoangCach = soNgay2 - soNgay1 + soNgayN1N2;
	return khoangCach;
}

void thoiGianTraDuKien(P1 listPhieuMuon[], int x)
{
	if (listPhieuMuon[x - 1].ngayMuon <= soNgayTrongThang(listPhieuMuon[x - 1].thangMuon, listPhieuMuon[x - 1].namMuon) - 6)
	{
		listPhieuMuon[x - 1].ngayTra = listPhieuMuon[x - 1].ngayMuon + 6;
		listPhieuMuon[x - 1].thangTra = listPhieuMuon[x - 1].thangMuon;
		listPhieuMuon[x - 1].namTra = listPhieuMuon[x - 1].namMuon;
	}
	else
	{
		if (listPhieuMuon[x - 1].thangMuon < 12)
		{
			listPhieuMuon[x - 1].ngayTra = listPhieuMuon[x - 1].ngayMuon + 6 - soNgayTrongThang(listPhieuMuon[x - 1].thangMuon, listPhieuMuon[x - 1].namMuon);
			listPhieuMuon[x - 1].thangTra++;
		}
		else	if (listPhieuMuon[x - 1].thangMuon == 12)
		{
			listPhieuMuon[x - 1].ngayTra = listPhieuMuon[x - 1].ngayMuon + 6 - soNgayTrongThang(listPhieuMuon[x - 1].thangMuon, listPhieuMuon[x - 1].namMuon);
			listPhieuMuon[x - 1].thangTra = 1;
			listPhieuMuon[x - 1].namTra++;
		}
	}
}

/*Ham Xuat Thong Tin Phieu Muon Sach	*/
void xuatPhieuMuon(P1 listPhieuMuon[], int x, char ISBNSachMuon[100][50])
{
	cout << "\n**************************************** PHIEU MUON SACH CUA DOC GIA **************************************************\n";
	cout << "* +Ma so doc gia muon sach: ";
	cout << listPhieuMuon[x - 1].maSoMuon << endl;
	cout << "* +Thoi diem muon sach cua do gia ma so " << listPhieuMuon[x - 1].maSoMuon << " la: " << listPhieuMuon[x - 1].ngayMuon << "/" << listPhieuMuon[x - 1].thangMuon << "/" << listPhieuMuon[x - 1].namMuon << endl;
	cout << "* +Thoi diem tra sach du kien cua do gia ma so " << listPhieuMuon[x - 1].maSoMuon << " la: " << listPhieuMuon[x - 1].ngayTra << "/" << listPhieuMuon[x - 1].thangTra << "/" << listPhieuMuon[x - 1].namTra;
	cout << "\n* +Danh sach ISBN cac sach duoc muon la:\n";
	for (int j = 0; j < listPhieuMuon[x - 1].soLuong; j++)
	{
		cout << "*\t +)ISBN cua quyen sach thu " << j + 1 << " la: ";
		puts(ISBNSachMuon[j]);
	}
	cout << "\n************************************************************************************************************************";
	cout << "\n------------------------------------------------------------------------------------------------------------------------";
	cout << "\n| LUU Y: ";
	cout << "\n|- Doc gia tre han tra sach(7 ngay ke tu ngay muon sach) cho thu vien se phat 5000VND/1ngaytre.";
	cout << "\n|- Neu mat sach se phai boi thuong 200%%  gia tri cua sach.\n";
}

void nhapPhieuTra(int x, int checkSach[100], P1 listPhieuMuon[], int& h, P2 phieuTra[], char ISBNSachMuon[100][50])
{
	while (1 < 2)
	{
		while (h < 100)
		{

			// Nhap ma doc gia tra sach:
		
			cout << "\n +)Nhap ma doc gia tra sach: ";
			cin >> phieuTra[h].maSoTra;

			// Nhap thoi diem tra sach thuc te:
			cout << "\t+Nhap ngay tra sach thuc te : ";
			cin >> phieuTra[h].ngayTraTT;
			cout << "\t+Nhap thang tra sach thuc te : ";
			cin >> phieuTra[h].thangTraTT;
			cout << "\t+Nhap nam tra sach thuc te : ";
			cin >> phieuTra[h].namTraTT;
			for (int i = 0; i < x; i++)
			{
				int j;
				for (j = 0; j < listPhieuMuon[i].soLuong; j++)
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

int tinhTienPhat(int x, P1 listPhieuMuon[], P2 phieuTra[])
{
	int soTien = 0;
	int khoangCach = khoangCachNgay(listPhieuMuon[x - 1].ngayTra, listPhieuMuon[x - 1].thangTra, listPhieuMuon[x - 1].namTra, phieuTra[x - 1].ngayTraTT, phieuTra[x - 1].thangTraTT, phieuTra[x - 1].namTraTT);
	if (khoangCach > 0)
	{
		soTien = khoangCach * 5000;
		return soTien;
	}
	return soTien;
}
int  checkPrice(char ISBNSachMuon[50],  int m, book s[])
{
	for (int i = 0; i < m; i++)
	{
		if (strcmp(ISBNSachMuon, s[i].ISBN) == 0)
			return s[i].giaSach;
	}
	return 0;
}

void xuatPhieuTra(int x,int checkSach[100], P1 listPhieuMuon[], char ISBNSachMuon[][50], int h, book b[],P2 phieuTra[],int m)
{
	int check = 0;
	int flag = 0;
	for (int i = 0; i < x; i++)
	{
		if (listPhieuMuon[i].maSoMuon == phieuTra[h - 1].maSoTra)
		{
			cout << "\n*************************************************** PHIEU TRA SACH CUA DOC GIA **************************************\n";
			cout << " +Ma so doc gia tra sach: ";
			cout<<listPhieuMuon[i].maSoMuon;
			cout << " +Thoi diem muon sach cua do gia ma so " << listPhieuMuon[i].maSoMuon << " la: " << listPhieuMuon[i].ngayMuon << "/" << listPhieuMuon[i].thangMuon << "/" << listPhieuMuon[i].namMuon;
			cout << "\n +Thoi diem tra sach du kien cua doc gia co ma so " << listPhieuMuon[i].maSoMuon << " la: " << listPhieuMuon[i].ngayTra << "/" << listPhieuMuon[i].thangTra << "/" << listPhieuMuon[i].namTra;
			cout << "\n +Thoi diem tra sach thuc te cua doc gia co ma so " << listPhieuMuon[i].maSoMuon << " la: " << phieuTra[i].ngayTraTT << "/" << phieuTra[i].thangTraTT << "/" << phieuTra[i].namTraTT;
			cout << "\n Danh sach ISBN cac sach duoc muon la:\n";
			for (int j = 0; j < listPhieuMuon[i].soLuong; j++)
			{
				cout << "\t +)ISBN cua quyen sach thu " << j + 1 << " la: ";
				puts(ISBNSachMuon[j]);
				if (checkSach[j] == 1)
					cout << "< Do lam mat sach nen quy khach phai den 200% theo gia bia cua quyen sach co ISBN " << ISBNSachMuon[j] << "la: " << checkPrice(ISBNSachMuon[j],m,b)<< ">" << endl;
			}


			cout << " +)So tien phat khi tra sach tre la: " << tinhTienPhat(x, listPhieuMuon, phieuTra) << "VND" << endl;
			cout << "==================================================================================================================\n";
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		cout << "Khong co thong tin doc gia tra sach!!";
}