#include"quanLyDocGia.h"
#include<string.h>
#include<cstdio>
#include<stdio.h>
#include<iostream>
using namespace std;
//danh sach sach
void danhSachSach(int n,int nBer[], char ISBN[][100], char tenSach[][50], char tacGia[][50], char nhaXB[][20], int namXB[],
	char theLoai[][30], int giaSach[], int soQuyenSach[])
	{
		cout << "\n\n  Danh Sach Cac Sach Co Trong Thu Vien" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "STT\t\t" << nBer[i] << endl;
			cout << "Ma Sach\t\t" << ISBN[i] << endl;
			cout << "Ten Sach\t" << tenSach[i] << endl;
			cout << "Tac Gia\t\t" << tacGia[i] << endl;
			cout << "Nha Xuat Ban\t" << nhaXB[i] << endl;
			cout << "Nam Xuat Ban\t" << namXB[i] << endl;
			cout << "The Loai\t" << theLoai[i] << endl;
			cout << "Gia Sach\t" <<giaSach[i] << endl;
			cout << "So Quyen Sach\t" << soQuyenSach[i] << endl << endl;
		}
	}
// them sach vao thu vien
void themSach(int &n, int nBer[], char ISBN[][100], char tenSach[][50], char tacGia[][50], char nhaXB[][20], int namXB[],
	char theLoai[][30], int giaSach[], int soQuyenSach[])
{
	nBer[n] = n+1;
	cin.ignore(1);
	cout << "Nhap Ma Sach\t";
	gets_s(ISBN[n]);
	cout << "\nNhap Ten Sach\t"; 
	gets_s(tenSach[n]);
	cout << "\nNhap Tac Gia\t";
	gets_s(tacGia[n]);
	cout << "\nNhap Nha Xuat Ban\t";
	gets_s(nhaXB[n]);
	cout << "\nNhap Nam Xuat Ban\t";
	cin >> namXB[n];
	cin.ignore(1);
	cout << "\nNhap The Loai\t";
	gets_s(theLoai[n]);
	cout << "\nNhap Gia Sach\t";
	cin >> giaSach[n];
	cout << "\nNhap So Quyen Sach\t";
	cin >> soQuyenSach[n];
	n++;
}
// xoa thon tin 1 quyen sach theo STT
void xoaSach(int k, int& n,int nBer[], char ISBN[][100], char tenSach[][50], char tacGia[][50], char nhaXB[][20], int namXB[],
	char theLoai[][30], int giaSach[], int soQuyenSach[])
{
	for (int i = k - 1; i < n - 1; i++)
	{
		strcpy_s(ISBN[i], ISBN[i + 1]);
		strcpy_s(tenSach[i], tenSach[i + 1]);
		strcpy_s(tacGia[i], tacGia[i + 1]);
		strcpy_s(nhaXB[i], nhaXB[i + 1]);
		namXB[i] = namXB[i + 1];
		strcpy_s(theLoai[i], theLoai[i + 1]);
		giaSach[i] = giaSach[i + 1];
		soQuyenSach[i] = soQuyenSach[i + 1];
	}
	n--;
}
// tim sach theo isbn
void timSachTheoISBN(int n, int nBer[], char ISBN[][100], char tenSach[][50], char tacGia[][50], char nhaXB[][20], int namXB[],
	char theLoai[][30], int giaSach[], int soQuyenSach[])
{
	char timISBN[100];
	cin.ignore(1);
	cout << "Nhap Ma Sach\t";
	gets_s(timISBN);
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(ISBN[i], timISBN) == 0)// So sanh 2 chuoi
		{
			cout << ("\n**************** Thong Tin Quyen Sach Can Tim ******************\n");
			// Xem ISBN cua sach:
			cout << "STT\t" << nBer[i];
			cout << "Ma Sach\t" << ISBN[i] << endl;
			cout << "Ten Sach\t" << tenSach[i] << endl;
			cout << "Tac Gia\t\t" << tacGia[i] << endl;
			cout << "Nha Xuat Ban\t" << nhaXB[i] << endl;
			cout << "Nam Xuat Ban\t" << namXB[i] << endl;
			cout << "The Loai\t" << theLoai[i] << endl;
			cout << "Gia Sach\t" << giaSach[i] << endl;
			cout << "So Quyen Sach\t" << soQuyenSach[i] << endl << endl;
			flag = 1;
		}
	}
	if (flag != 1)
		cout << "\nKhong tim thay!!!";
}
// tim sach theo ten sach
void timSachTheoTen(int n,int nBer[], char ISBN[][100], char tenSach[][50], char tacGia[][50], char nhaXB[][20], int namXB[],
	char theLoai[][30], int giaSach[], int soQuyenSach[])
{
	char timTheoTenSach[100]; 
	cin.ignore(1);
	cout << "Nhap Ten Sach\t";
	gets_s(timTheoTenSach);
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(tenSach[i], timTheoTenSach) == 0)// So sanh 2 chuoi
		{
			cout << ("\n**************** Thong Tin Quyen Sach Can Tim ******************\n");
			// Xem thong tin  cua sach theo ten da nhap
			cout << "STT\t" << nBer[i];
			cout << "Ma Sach\t" << ISBN[i] << endl;
			cout << "Ten Sach\t" << tenSach[i] << endl;
			cout << "Tac Gia\t\t" << tacGia[i] << endl;
			cout << "Nha Xuat Ban\t" << nhaXB[i] << endl;
			cout << "Nam Xuat Ban\t" << namXB[i] << endl;
			cout << "The Loai\t" << theLoai[i] << endl;
			cout << "Gia Sach\t" << giaSach[i] << endl;
			cout << "So Quyen Sach\t" << soQuyenSach[i] << endl << endl;
			flag = 1;
		}
	}
	if (flag != 1)
		cout << "\nKhong tim thay!!!";
}
//chinh sua thong tin sach
void edit(int k,int nBer[], char ISBN[][100], char tenSach[][50], char tacGia[][50], char nhaXB[][20], int namXB[],
	char theLoai[][30], int giaSach[], int soQuyenSach[])
{
	while (1 < 2)
	{
		int choice;
		cout << "\n************************************************************************************************************************";
		cout << "\t\t<1>:Chinh sua ISBN cua quyen sach.\n";
		cout << "\t <2>:Chinh sua ten sach.\n";
		cout << "\t <3>:Chinh sua tac gia cua quyen sach.\n";
		cout << "\t <4>:Chinh sua nha xuat ban cua quyen sach.\n";
		cout << "\t <5>:Chinh sua nam xuat ban cua quyen sach.\n";
		cout << "\t <6>:Chinh sua the loai cua quyen sach.\n";
		cout << "\t <7>:Chinh sua gia ban cua quyen sach.\n";
		cout << "\t <8>:chinh sua so luong cua moi quyen sach.\n";
		cout << "\t <0>:ket thuc chinh sua\n";
		cout << "\n************************************************************************************************************************";
		cout << "\n Chon chuc nang\t";
		cin >> choice;
		if (choice == 0)
		{
			break;
		}
		else	if (choice == 5)
		{
			int sua;
			cout << "\n---Chinh sua nam xuat ban cua quyen sach---";
			cout << "\nnhap lai nam xuat ban\t";
			cin >> sua;
			namXB[k - 1] = sua;
			break;
		}
		else if (choice == 7)
		{
			int sua;
			cout << "\t nhap gia moi\t";
			cin >> sua;
			giaSach[k - 1] = sua;
			break;
		}
		else if (choice == 8)
		{
			int sua;
			cout << "\t nhap lai so luong quyen sach\t";
			cin >> sua;
			soQuyenSach[k - 1] = sua;
			break;
		}
		else
		{
			
			cin.ignore(1);
			char sua1[100];
			cout<<"\nNhap noi dung chinh sua:\t";
			gets_s(sua1);
			if (choice == 1)
			{
				strcpy_s(ISBN[k - 1], sua1);
				break;
			}

		else	if (choice == 2)
			{
				strcpy_s(tenSach[k - 1], sua1);
				break;
			}
			else if (choice == 3)
			{
				strcpy_s(tacGia[k - 1], sua1);
				break;
			}
			else if (choice == 4)
			{
				strcpy_s(nhaXB[k - 1], sua1);
				break;
			}
			else if (choice == 6)
			{
				strcpy_s(theLoai[k - 1], sua1);
				break;
			}
			else
				cout << "\n\t\t\tNHAP LAI ????????!!!!!!!!!!" << endl;
		}
	}
}
//xem lai thong tin sach sau khi da sua
void xemThongTinSachDaSua(int k, int nBer[], char ISBN[][100], char tenSach[][50], char tacGia[][50], char nhaXB[][20], int namXB[],
	char theLoai[][30], int giaSach[], int soQuyenSach[])
{
	cout<<"\n************************ Thong Tin Quyen Sach Thu "<<k<< " Sau Khi Chinh Sua ****************************\n";

	// Xem ISBN cua sach:
	cout << "STT\t\t" << nBer[k-1] << endl;
	cout << "Ma Sach\t\t" << ISBN[k-1] << endl;
	cout << "Ten Sach\t" << tenSach[k-1] << endl;
	cout << "Tac Gia\t\t" << tacGia[k-1] << endl;
	cout << "Nha Xuat Ban\t" << nhaXB[k-1] << endl;
	cout << "Nam Xuat Ban\t" << namXB[k-1] << endl;
	cout << "The Loai\t" << theLoai[k-1] << endl;
	cout << "Gia Sach\t" << giaSach[k-1] << endl;
	cout << "So Quyen Sach\t" << soQuyenSach[k-1] << endl << endl;
}