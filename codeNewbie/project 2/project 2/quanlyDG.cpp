#include"quanLyDG.h"
#include<string.h>
#include<fstream>
#include<iostream>
using namespace std;
void nhapDG(DG& d)
{
	cout << "\n\t\t\tNhap Ma So\t";
	cin >> d.maSoDG;
	cin.ignore(1);
	cout << "\n\t\t\tNhap ho va ten\t";
	gets_s(d.hoTenDG);
	cout << "\n\t\t\tNhap so CMND\t";
	gets_s(d.CMNDDG);
	cout << "\n\t\t\tNhap ngay thang nam sinh(dd/mm/yy) \t";
	gets_s(d.ngaySinhDG);
	cout << "\n\t\t\tNhap gioi tinh(1: Nam, 0: nu)\t";
	cin >> d.gioiTinhDG;
	cout << "\n\t\t\tNhap email\t";
	gets_s(d.emailDG);
	gets_s(d.emailDG);
	cout << "\n\t\t\tNhap dia chi\t";
	gets_s(d.diaChiDG);
	cout << "\n\t\t\tNhap ngay lap\t"; cin >> d.ngayLap; cout << "\n\t\t\tNhap thang lap \t"; cin >> d.thangLap; cout << "\n\t\t\tNhap nam lap\t"; cin >> d.namLap;

}
void nhapDSDG(DG listDG[], int n1,int &n)
{
	
	for (int i = n; i < n + n1; i++)
	{
		cout << "\n\t+Nhap doc gia thu " << i + 1 << endl;
		nhapDG(listDG[i]);
	}
	n = n + n1;
}
/*
void nhapDSDG(DG listDG[], int n)
{
	for (int i = 0; i < n; i++)

	{
		cout << "\n\t+Nhap doc gia thu " << i + 1 << endl;
		nhapDG(listDG[i]);
	}
}*/
void saveFileDG(DG listDG[], int n)
{
	ofstream outFile;
	outFile.open("docGia.txt", ofstream::binary);
	for (int i = 0; i < n; i++)
	{
		DG b = listDG[i];
		outFile.write((char*)&b, sizeof(DG));
	}
	outFile.close();
}
void docFileDG(DG listDG[], int &n)
{
	ifstream inFile;
	inFile.open("docGia.txt", ifstream::binary);
	inFile.seekg(0, inFile.end);
	int size = inFile.tellg();
	inFile.seekg(0);
	n = size / sizeof(DG);
	for (int i = 0; i < n; i++)
	{
		DG b;
		inFile.read((char*)&b, sizeof(DG));
		listDG[i] = b;
	}
	inFile.close();
}
void xuatDG(DG d)
{
	
		cout << "Ma so\t\t" << d.maSoDG << endl;
		cout << "Ho va Ten:\t" << d.hoTenDG << endl;
		cout << "So CMND\t\t" << d.CMNDDG << endl;
		cout << "Ngay sinh:\t" << d.ngaySinhDG << endl;
		if (d.gioiTinhDG == 1)
			cout << "Gioi tinh:\tNam" << endl;
		else
			cout << "Gioi tinh:\tNu" << endl;
		cout << "Email:\t\t" << d.emailDG << endl;
		cout << "Dia chi:\t" << d.diaChiDG << endl;
		cout << "Ngay lap the:\t" << d.ngayLap << "/" << d.thangLap << "/" << d.namLap << endl;
		cout << "Ngay het han:\t" << d.ngayLap<< "/" << d.thangLap << "/" << d.namLap + 4 << endl << endl;
	}
void xuatListDG(DG listDG[], int n)
{
	for (int i = 0; i < n; i++)
		xuatDG(listDG[i]);
}
void editDG(DG listDG[], int n)
{
	int k;
	cout << "nhap ma doc gia can chinh sua ";
	cin >> k;
	if (k<0 || k>n)
		cout << "\t\t\t\tMa so doc gia khong ton tai!!!!!\n\n";
	else
	{
		for (int i = 0; i < n; i++)
		{
			
			if (listDG[i].maSoDG == k)
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
						listDG[i].gioiTinhDG = sua;
						saveFileDG(listDG, n);
						cout << "\t\t\t\t|| XONG ||" << endl;
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
						listDG[i].ngayLap = ngay;
						listDG[i].thangLap = thang;
						listDG[i].namLap = nam;
						saveFileDG(listDG, n);
						cout << "\t\t\t\t|| XONG ||" << endl;
						break;
					}

					if (choice == 1 || choice == 3 || choice == 5 || choice == 6)
					{
						cin.ignore(1);
						char sua1[100];
						cout << "\nNhap noi dung chinh sua:\t";
						gets_s(sua1);
						if (choice == 2)
						{
							strcpy_s(listDG[i].CMNDDG, sua1);
							saveFileDG(listDG, n);
							cout << "\t\t\t\t|| XONG ||" << endl;
							break;
						}
						else if (choice == 1)
						{
							strcpy_s(listDG[i].hoTenDG, sua1);
							saveFileDG(listDG, n);
							cout << "\t\t\t\t|| XONG ||" << endl;
							break;
						}
						else if (choice == 3)
						{
							strcpy_s(listDG[i].ngaySinhDG, sua1);
							saveFileDG(listDG, n);
							cout << "\t\t\t\t|| XONG ||" << endl;
							break;
						}
						else if (choice == 5)
						{
							strcpy_s(listDG[i].emailDG, sua1);
							saveFileDG(listDG, n);
							cout << "\t\t\t\t|| XONG ||" << endl;
							break;
						}
						else if (choice == 6)
						{
							strcpy_s(listDG[i].diaChiDG, sua1);
							saveFileDG(listDG, n);
							cout << "\t\t\t\t|| XONG ||" << endl;
							break;
						}
						else
							cout << "\n\t\t\tNHAP LAI ????????!!!!!!!!!!" << endl;
						break;
					}
					cout << "\n\t\t\tNHAP LAI ????????!!!!!!!!!!" << endl;
					break;
				}
			}
		}
	}
}

void delDG(DG listDG[], int &n)
{
	int k;
	cout << "nhap ma doc gia can xoa ";
	cin >> k;
	if (k<0 || k>n)
		cout << "\t\t\t\tMa so doc gia khong ton tai!!!!!" << n;
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (listDG[i].maSoDG == k)
			{
				for (int j = i; j < n-1 ; j++)
				{
					
					listDG[j].maSoDG = listDG[j + 1].maSoDG;
					strcpy_s(listDG[j].hoTenDG, listDG[j+1].hoTenDG);
					strcpy_s(listDG[j].CMNDDG, listDG[j+1].CMNDDG);
					strcpy_s(listDG[j].ngaySinhDG, listDG[j+1].ngaySinhDG);
					listDG[j].gioiTinhDG = listDG[j+1].gioiTinhDG;
					strcpy_s(listDG[j].emailDG, listDG[j+1].emailDG);
					strcpy_s(listDG[j].diaChiDG, listDG[j+1].diaChiDG);
					listDG[j].ngayLap = listDG[j + 1].ngayLap;
					listDG[j].thangLap = listDG[j+1].thangLap;
					listDG[j].namLap = listDG[j + 1].namLap;
					cout<<"\t\t\t\t DA XOA!!"<<endl;
				}
				n--;
				break;
			}
		}
	}
}
	
void searchCMND(DG listDG[], int n, char search[])
{
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(listDG[i].CMNDDG, search) == 0)
		{
			cout << "\n\t\t\t\tTHONG TIN DOC GIA DA TIM" << endl;
			xuatDG(listDG[i]);
			flag = 1;
		}
	}
	if (flag == 0)
		cout << "\n\t\t\tKHONG TIM THAY!!!\n\n";
}

void searchName(DG listDG[], int n, char search[])
{
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(listDG[i].hoTenDG, search) == 0)
		{
			cout << "\n\t\t\t\tTHONG TIN DOC GIA DA TIM" << endl;
			xuatDG(listDG[i]);
			flag = 1;
		}
	}
	if (flag == 0)
		cout << "\n\t\t\tKHONG TIM THAY!!!\n\n";
}

