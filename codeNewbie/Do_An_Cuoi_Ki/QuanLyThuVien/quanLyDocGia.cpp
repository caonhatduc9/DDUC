#include"quanlyDocGia.h"
#include<string.h>
#include<cstdio>
#include<stdio.h>
#include<iostream>
using namespace std;

//xem thong tin doc gia
void danhSachDocGia(int n, int maSoDG[], char hoTenDG[][70], char CMNDDG[][10], char ngaySinhDG[][15], int gioiTinhDG[], char emailDG[][100],
	char diaChiDG[][300], int ngayLap[], int thangLap[], int namLap[])
{
	cout << "\n\n                      DANH SACH DOC GIA CO " << n << " THANH VIEN" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "thanh vien thu\t" << i + 1 << endl;
		cout << "Ma so\t\t" << maSoDG[i] << endl;
		cout << "Ho va Ten:\t" << hoTenDG[i] << endl;
		cout << "So CMND\t\t" << CMNDDG[i] << endl;
		cout << "Ngay sinh:\t" << ngaySinhDG[i] << endl;
		if (gioiTinhDG[i] == 1)
		cout << "Gioi tinh:\tNam"<< endl;
		else
			cout << "Gioi tinh:\tNu" << endl;
		cout << "Email:\t\t" << emailDG[i] << endl;
		cout << "Dia chi:\t" << diaChiDG[i] << endl;
		cout << "Ngay lap the:\t" << ngayLap[i] << "/" << thangLap[i] << "/" << namLap[i] << endl;
		cout << "Ngay het han:\t" << ngayLap[i] << "/" << thangLap[i] << "/" << namLap[i] + 4 << endl << endl;
	}
}

//xoa thong tin doc gia
void xoaDocGia(int k, int &n, int maSoDG[], char hoTenDG[][70], char CMNDDG[][10], char ngaySinhDG[][15], int gioiTinhDG[], char emailDG[][100],
	char diaChiDG[][300], int ngayLap[], int thangLap[], int namLap[])
{
	for (int i = k-1; i < n - 1; i++)
	{
		maSoDG[i] = maSoDG[i+1];
		strcpy_s(hoTenDG[i], hoTenDG[i+1]);
		strcpy_s(CMNDDG[i], CMNDDG[i + 1]);
		strcpy_s(ngaySinhDG[i], ngaySinhDG[i+1]);
		gioiTinhDG[i] = gioiTinhDG[i + 1];
		strcpy_s(emailDG[i], emailDG[i + 1]);
		strcpy_s(diaChiDG[i], diaChiDG[i + 1]);
		ngayLap[i] = ngayLap[i + 1];
		thangLap[i] = thangLap[i + 1];
		namLap[i] = namLap[i + 1];
	}
	n--;
}

//them doc gia
void themDocGia(int& n, int maSoDG[], char hoTenDG[][70], char CMNDDG[][10], char ngaySinhDG[][15], int gioiTinhDG[], char emailDG[][100],
	char diaChiDG[][300], int ngayLap[], int thangLap[], int namLap[])
{

	cout << "\nNhap Ma So\t";
	cin >> maSoDG[n];
	cin.ignore(1);
	cout << "\nNhap ho va ten\t";
	gets_s(hoTenDG[n]);
	cout << "\nNhap so CMND\t";
	gets_s(CMNDDG[n]);
	cout << "\nNhap ngay thang nam sinh(dd/mm/yy) \t";
	gets_s(ngaySinhDG[n]);
	cout << "\nNhap gioi tinh(1: Nam, 0: nu)\t";
	cin >> gioiTinhDG[n];
	cout << "\nNhap email\t";
	gets_s(emailDG[n]);
	gets_s(emailDG[n]);
	cout << "\nNhap dia chi\t";
	gets_s(diaChiDG[n]);
	cout << "\nNhap ngay lap\t"; cin >> ngayLap[n]; cout << "\nNhap thang lap \t"; cin >> thangLap[n]; cout << "\nNhap nam lap\t"; cin >> namLap[n];
	n++;
}
//tim kiem thong tin doc gia theo CMND
void timDGTheoCMND(int n, int maSoDG[], char hoTenDG[][70], char CMNDDG[][10], char ngaySinhDG[][15], int gioiTinhDG[], char emailDG[][100],
	char diaChiDG[][300], int ngayLap[], int thangLap[], int namLap[])
{
	char timCMND[100];
	cin.ignore(1);
	cout << "Nhap CMND Can Tim\t";
	gets_s(timCMND);
	int flag = 69;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(CMNDDG[i], timCMND) == 0)// So sanh 2 chuoi
		{
			cout << ("\n**************** Thong Tin Doc Gia Can Tim ******************\n");
			// Xem thong tin Doc Gia theo CMND da nhap:
			cout << "Ma So\t" << maSoDG[i] << endl;
			cout << "Ho Ten \t" << hoTenDG[i] << endl;
			cout << "CMND\t\t" << CMNDDG[i] << endl;
			cout << "Ngay Sinh\t" <<ngaySinhDG[i] << endl;
			cout << "Gioi Tinh\t" << gioiTinhDG[i] << endl;
			cout << "Email\t" << emailDG[i] << endl;
			cout << "Dia Chi\t" << diaChiDG[i] << endl;
			cout << "Ngay lap the:\t" << ngayLap[i] << "/" << thangLap[i] << "/" << namLap[i] << endl;
			cout << "Ngay het han:\t" << ngayLap[i] << "/" << thangLap[i] << "/" << namLap[i] + 4 << endl << endl;
			flag = 1;
		}
	}
	if (flag != 1)
		cout << "\n                  KHONG TIM THAY!!!                           \n\n";
}
//tim kiem doc gia theo ten
void timDGTheoTen(int n, int maSoDG[], char hoTenDG[][70], char CMNDDG[][10], char ngaySinhDG[][15], int gioiTinhDG[], char emailDG[][100],
	char diaChiDG[][300], int ngayLap[], int thangLap[], int namLap[])
{
	char timTenDG[100];
	cin.ignore(1);
	cout << "Nhap Ten Can Tim\t";
	gets_s(timTenDG);
	int flag = 69;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(hoTenDG[i], timTenDG) == 0)// So sanh 2 chuoi
		{
			cout << ("\n**************** Thong Tin Doc Gia Can Tim ******************\n");
			// Xem thong tin Doc Gia theo Ten da nhap:
			cout << "Ma So\t" << maSoDG[i] << endl;
			cout << "Ho Ten \t\t" << hoTenDG[i] << endl;
			cout << "CMND\t\t" << CMNDDG[i] << endl;
			cout << "Ngay Sinh\t" << ngaySinhDG[i] << endl;
			cout << "Gioi Tinh\t" << gioiTinhDG[i] << endl;
			cout << "Email\t\t" << emailDG[i] << endl;
			cout << "Dia Chi\t\t" << diaChiDG[i] << endl;
			cout << "Ngay lap the:\t" << ngayLap[i] << "/" << thangLap[i] << "/" << namLap[i] << endl;
			cout << "Ngay het han:\t" << ngayLap[i] << "/" << thangLap[i] << "/" << namLap[i] + 4 << endl << endl;
			flag = 1;
		}
	}
	if (flag != 1)
		cout << "\n                  KHONG TIM THAY!!!                           \n\n";
}
//chinh sua thong tin doc gia theo ma so doc gia
void editDG(int k, int maSoDG[], char hoTenDG[][70], char CMNDDG[][10], char ngaySinhDG[][15], int gioiTinhDG[], char emailDG[][100],
	char diaChiDG[][300], int ngayLap[], int thangLap[], int namLap[])
{
	while (1 < 2)
	{
		int choice;
		cout << "\n***********************************************************************************************************************";
		cout << "\n\t <1>:Chinh sua ho va ten doc gia .\n";
		cout << "\t <2>:Chinh sua so CMND doc gia.\n";
		cout << "\t <3>:Chinh sua ngay sinh doc gia.\n";
		cout << "\t <4>:Chinh sua gioi tinh doc gia.\n";
		cout << "\t <5>:Chinh sua email doc gia.\n";
		cout << "\t <6>:Chinh sua dia chi doc gia.\n";
		cout << "\t <7>:Chinh sua ngay lap the cua doc gia.\n";
		cout << "\t <0>:ket thuc chinh sua\n";
		cout << "************************************************************************************************************************\n";
		cout << "\n Chon chuc nang\t";
		cin >> choice;
		if (choice == 0)
		{
			break;
		}
		if (choice == 4)
		{
			int sua;
			cout << "\nnhap lai gioi tinh doc gia(1:nam,0:nu)\t";
			cin >> sua;
			gioiTinhDG[k - 1] = sua;
			break;
		}
		else if (choice == 7)
		{
			int ngay, thang, nam;
			cout << "\t nhap ngay lap\t";
			cin >> ngay;
			cout << "\n\t nhap thang lap\t";
			cin >> thang;
			cout << "\n\t nhap nam lap\t";
			cin >> nam;
			ngayLap[k - 1] = ngay;
			thangLap[k - 1] = thang;
			namLap[k - 1] = nam;
			break;
		}
		
		else
		{
			cin.ignore(1);
			char sua1[100];
			cout << "\nNhap noi dung chinh sua:\t";
			gets_s(sua1);
			if (choice == 2)
			{
				strcpy_s(CMNDDG[k - 1], sua1);
				break;
			}
			else if (choice == 1)
			{
				strcpy_s(hoTenDG[k - 1], sua1);
				break;
			}
			else if (choice == 3)
			{
				strcpy_s(ngaySinhDG[k - 1], sua1);
				break;
			}
			else if (choice == 5)
			{
				strcpy_s(emailDG[k - 1], sua1);
				break;
			}
			else if (choice == 6)
			{
				strcpy_s(diaChiDG[k - 1], sua1);
				break;
			}
			else
				cout << "\n\t\t\tNHAP LAI ????????!!!!!!!!!!" << endl;
		}
	}
}
//xem lai thong tin sach sau khi da sua
void xemThongTinDocGiaDaSua(int k, int maSoDG[], char hoTenDG[][70], char CMNDDG[][10], char ngaySinhDG[][15], int gioiTinhDG[], char emailDG[][100],
	char diaChiDG[][300], int ngayLap[], int thangLap[], int namLap[])
{
	cout << "\n************************ Thong Tin Doc Gia Thu " << k << " Sau Khi Chinh Sua ****************************\n";

	
	cout << "Ma So Doc Gia\t" << maSoDG[k - 1] << endl;
	cout << "Ho Va Ten Doc Gia\t" << hoTenDG[k - 1] << endl;
	cout << "CMND\t\t\t" << CMNDDG[k - 1] << endl;
	cout << "Ngay Sinh\t\t" << ngaySinhDG[k - 1] << endl;
	if (gioiTinhDG[k-1] == 1)
		cout << "Gioi tinh:\t\tNam" << endl;
	else
		cout << "Gioi tinh:\t\tNu" << endl;
	cout << "Email\t\t\t" << emailDG[k - 1] << endl;
	cout << "Dia Chi\t\t\t" << diaChiDG[k - 1] << endl;
	cout << "Ngay lap the:\t\t" << ngayLap[k-1] << "/" << thangLap[k-1] << "/" << namLap[k-1] << endl;
	cout << "Ngay het han:\t\t" << ngayLap[k-1] << "/" << thangLap[k-1] << "/" << namLap[k-1] + 4 << endl << endl;
}