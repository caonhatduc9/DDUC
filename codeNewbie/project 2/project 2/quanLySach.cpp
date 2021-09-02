#include"quanLySach.h"
#include<string.h>
#include<fstream>
#include<iostream>
using namespace std;

void nhapSach(book &b)
{

	cin.ignore(1);
	cout << "Nhap Ma Sach\t";
	gets_s(b.ISBN);
	cout << "\nNhap Ten Sach\t";
	gets_s(b.tenSach);
	cout << "\nNhap Tac Gia\t";
	gets_s(b.tacGia);
	cout << "\nNhap Nha Xuat Ban\t";
	gets_s(b.nhaXB);
	cout << "\nNhap Nam Xuat Ban\t";
	cin >> b.namXB;
	cout << "\nNhap The Loai\t";
	cin.ignore(1);
	gets_s(b.theLoai);
	cout << "\nNhap Gia Sach\t";
	cin >> b.giaSach;
	cout << "\nNhap So Quyen Sach\t";
	cin >> b.soQuyenSach;
}
// them  sach
void nhapDSSach(book listBook[], int& m)
{
	int m1;
	cout << "\n\nNhap so sach muon nhap: ";
	cin >> m1;
	for (int i = m; i < m+m1; i++)

	{
		cout << "\n\t+Nhap sach thu " << i + 1 << endl;
		nhapSach(listBook[i]);
	}
	m = m + m1;
}

void xuatSach(book bb)
{

	cout << "Ma Sach\t\t" << bb.ISBN << endl;
	cout << "Ten Sach\t" << bb.tenSach << endl;
	cout << "Tac Gia\t\t" << bb.tacGia << endl;
	cout << "Nha Xuat Ban\t" << bb.nhaXB << endl;
	cout << "Nam Xuat Ban\t" << bb.namXB << endl;
	cout << "The Loai\t" << bb.theLoai<< endl;
	cout << "Gia Sach\t" << bb.giaSach << "VND" << endl;
	cout << "So Quyen Sach\t" << bb.soQuyenSach << endl << endl;
}
//xuat danh sach cac sach
void xuatListSach(book listBook[], int m)
{
	for (int i = 0; i < m; i++)
	{
		xuatSach(listBook[i]);
	}
}

//luu vao file danh sach sach
void saveFileSach(book listBook[], int m)
{
	ofstream outFile;
	outFile.open("sach.txt", ofstream::binary);
	for (int i = 0; i < m; i++)
	{
		book b = listBook[i];
		outFile.write((char*)&b, sizeof(book));
	}
	outFile.close();
}
//load file danh sach sach
void docFileSach(book listBook[], int& m)
{
	ifstream inFile;
	inFile.open("sach.txt", ifstream::binary);
	if (!inFile)
		cout << "\n\t\t\t\tKHONG MO FILE DUOC" << endl;
	inFile.seekg(0, inFile.end);
	int size = inFile.tellg();
	inFile.seekg(0);
	m = size / sizeof(book);
	for (int i = 0; i < m; i++)
	{
		book b;
		inFile.read((char*)&b, sizeof(book));
		listBook[i] = b;
	}
	inFile.close();
}
// chinh sua sach theo ten hoa ISBN nhap vao
void editBook(book listBook[], int m)
{
	int flag = 0;
	while (1 < 2)
	{
		int choice;
		cout << "\n***********************************************************************************************************************";
		cout << "\n\t <1>:Chinh sua theo ten sach .\n";
		cout << "\t <2>:Chinh sua theo ISBN sach.\n";
		cout << "\t <0>:Quay lai.\n";
		cout << "\n\n\t\t\tCHON CHUC NANG!! ";
		cin >> choice;	
		if (choice == 0)
			break;
		else if (choice == 1)
		{
			char l[100];
			cin.ignore(1);
			cout << "Nhap ten sach can chinh sua ";
			gets_s(l);
			for (int i = 0; i < m; i++)
			{
				if (strcmp(listBook[i].tenSach, l) == 0)
				{
					flag = 1;
					while (1 < 2)
					{
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
							listBook[i].namXB = sua;
							saveFileSach(listBook, m);
							cout << "\t\t\t\t|| XONG ||" << endl;
							break;
						}
						else if (choice == 7)
						{
							int sua;
							cout << "\t nhap gia moi\t";
							cin >> sua;
							listBook[i].giaSach = sua;
							saveFileSach(listBook, m);
							cout << "\t\t\t\t|| XONG ||" << endl;
							break;
						}
						else if (choice == 8)
						{
							int sua;
							cout << "\t nhap lai so luong quyen sach\t";
							cin >> sua;
							listBook[i].soQuyenSach = sua;
							saveFileSach(listBook, m);
							cout << "\t\t\t\t|| XONG ||" << endl;
							break;
						}
						else
						{

							cin.ignore(1);
							char sua1[100];
							cout << "\nNhap noi dung chinh sua:\t";
							gets_s(sua1);
							if (choice == 1)
							{
								strcpy_s(listBook[i].ISBN, sua1);
								saveFileSach(listBook, m);
								cout << "\t\t\t\t|| XONG ||" << endl;
								break;
							}

							else	if (choice == 2)
							{
								strcpy_s(listBook[i].tenSach, sua1);
								saveFileSach(listBook, m);
								cout << "\t\t\t\t|| XONG ||" << endl;
								break;
							}
							else if (choice == 3)
							{
								strcpy_s(listBook[i].tacGia, sua1);
								saveFileSach(listBook, m);
								cout << "\t\t\t\t|| XONG ||" << endl;
								break;
							}
							else if (choice == 4)
							{
								strcpy_s(listBook[i].nhaXB, sua1);
								saveFileSach(listBook, m);
								cout << "\t\t\t\t|| XONG ||" << endl;
								break;
							}
							else if (choice == 6)
							{
								strcpy_s(listBook[i].theLoai, sua1);
								saveFileSach(listBook, m);
								cout << "\t\t\t\t|| XONG ||" << endl;
								break;
							}
							else
								cout << "\n\t\t\tNHAP LAI ????????!!!!!!!!!!" << endl;
						}
					}
				}
				break;
			}
			if (flag == 0)
				cout << "\t\t\t\tKHONG TIM THAY TEN SACH!!!" << endl;
		}
		else if (choice == 2)
		{
			char h[100];
			cin.ignore(1);
			cout << "Nhap ma ISBN can chinh sua ";
			gets_s(h);
			for (int j = 0; j < m; j++)
			{
				if (strcmp(listBook[j].ISBN, h) == 0)
				{
					flag = 1;
					while (1 < 2)
					{
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
							listBook[j].namXB = sua;
							saveFileSach(listBook, m);
							cout << "\t\t\t\t|| XONG ||" << endl;
							break;
						}
						else if (choice == 7)
						{
							int sua;
							cout << "\t nhap gia moi\t";
							cin >> sua;
							listBook[j].giaSach = sua;
							saveFileSach(listBook, m);
							break;
						}
						else if (choice == 8)
						{
							int sua;
							cout << "\t nhap lai so luong quyen sach\t";
							cin >> sua;
							listBook[j].soQuyenSach = sua;
							saveFileSach(listBook, m);
							cout << "\t\t\t\t|| XONG ||" << endl;
							break;
						}
						else
						{

							cin.ignore(1);
							char sua1[100];
							cout << "\nNhap noi dung chinh sua:\t";
							gets_s(sua1);
							if (choice == 1)
							{
								strcpy_s(listBook[j].ISBN, sua1);
								saveFileSach(listBook, m);
								cout << "\t\t\t\t|| XONG ||" << endl;
								break;
							}

							else	if (choice == 2)
							{
								strcpy_s(listBook[j].tenSach, sua1);
								saveFileSach(listBook, m);
								cout << "\t\t\t\t|| XONG ||" << endl;
								break;
							}
							else if (choice == 3)
							{
								strcpy_s(listBook[j].tacGia, sua1);
								saveFileSach(listBook, m);
									cout << "\t\t\t\t|| XONG ||" << endl;
								break;
							}
							else if (choice == 4)
							{
								strcpy_s(listBook[j].nhaXB, sua1);
								saveFileSach(listBook, m);
								cout << "\t\t\t\t|| XONG ||" << endl;
								break;
							}
							else if (choice == 6)
							{
								strcpy_s(listBook[j].theLoai, sua1);
								saveFileSach(listBook, m);
								cout << "\t\t\t\t|| XONG ||" << endl;
								break;
							}
							else
								cout << "\n\t\t\tNHAP LAI ????????!!!!!!!!!!" << endl;
						}
					}
				}
			}
			if (flag == 0)
			{
				cout << "\t\t\t\tKHONG TIM THAY ISBN" << endl;
				break;
			}
			break;
		}
	}
}


void delBook(book listBook[], int& m)
{
	while (1 < 2)
	{
		int choice;
		cout << "\n***********************************************************************************************************************";
		cout << "\n\t <1>:Xoa theo ten sach .\n";
		cout << "\t <2>:Xoa theo ISBN sach.\n";
		cout << "\t <0>:Quay lai.\n";
		cout << "\n\n\t\t\tCHON CHUC NANG:  ";
		cin >> choice;
		int flag = 0;
		if (choice == 0)
			break;
		else if (choice == 1)
		{
			char k[100];
			cin.ignore(1);
			cout << "\t\t+nhap ten sach can xoa ";
			gets_s(k);
			for (int i = 0; i < m; i++)
			{
				if (strcmp(listBook[i].tenSach, k) == 0)
				{
					flag = 1;
					for (int j = i; j < m - 1; j++)
					{

						strcpy_s(listBook[j].ISBN, listBook[j + 1].ISBN);
						strcpy_s(listBook[j].tenSach, listBook[j + 1].tenSach);
						strcpy_s(listBook[j].tacGia, listBook[j + 1].tacGia);
						strcpy_s(listBook[j].nhaXB, listBook[j + 1].nhaXB);
						listBook[j].namXB = listBook[j + 1].namXB;
						strcpy_s(listBook[j].theLoai, listBook[j + 1].theLoai);
						listBook[j].giaSach = listBook[j + 1].giaSach;
						listBook[j].soQuyenSach = listBook[j + 1].soQuyenSach;
						
					}
					cout << "\t\t\t\t DA XOA!!" << endl;
					m--;
					break;
				}
			}
			if (flag == 0)
				cout<<"\t\t\t\tKHONG TIM THAY" << endl;
		}
		else if (choice == 2)
		{
			char h[100];
			cin.ignore(1);
			cout << "\t\t+nhap ma ISBN cua sach can xoa ";
			gets_s(h);
			for (int i = 0; i < m; i++)
			{
				if (strcmp(listBook[i].ISBN, h) == 0)
				{
					flag = 1;
					for (int j = i; j < m - 1; j++)
					{

						strcpy_s(listBook[j].ISBN, listBook[j + 1].ISBN);
						strcpy_s(listBook[j].tenSach, listBook[j + 1].tenSach);
						strcpy_s(listBook[j].tacGia, listBook[j + 1].tacGia);
						strcpy_s(listBook[j].nhaXB, listBook[j + 1].nhaXB);
						listBook[j].namXB = listBook[j + 1].namXB;
						strcpy_s(listBook[j].theLoai, listBook[j + 1].theLoai);
						listBook[j].giaSach = listBook[j + 1].giaSach;
						listBook[j].soQuyenSach = listBook[j + 1].soQuyenSach;
						
					}
					cout << "\t\t\t\t DA XOA!!" << endl;
					m--;
					break;
				}
			}
			if (flag == 0)
				cout<<"\t\t\t\tKHONG TIM THAY" << endl;
		}

	}
}

void searchISBN(book listBook[], int m, char search[])
{
	int flag = 0;
	for (int i = 0; i < m; i++)
	{
		if (strcmp(listBook[i].ISBN, search) == 0)
		{
			cout << "\n\t\t\tThong tin sach ban da tim kiem\n";
			xuatSach(listBook[i]);
			flag = 1;
		}
	}
	if (flag == 0)
		cout << "\n\t\t\tKHONG TIM THAY!!!\n\n";
}

void searchNameBook(book listBook[], int m, char search[])
{
	int flag = 0;
	for (int i = 0; i < m; i++)
	{
		if (strcmp(listBook[i].tenSach, search) == 0)
		{
			cout << "\n\t\t\tThong tin sach ban da tim kiem\n";
			xuatSach(listBook[i]);
			flag = 1;
		}
	}
	if (flag == 0)
		cout << "\n\t\t\tKHONG TIM THAY!!!\n\n";
}
