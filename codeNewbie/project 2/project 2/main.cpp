#include"quanLyDG.h"
#include"quanLySach.h"
#include"phieuMuonTra.h"
#include"thongKe.h"
#include<string>
#include<iostream>
using namespace std;


int main()
{
	DG  listDG[100];
	book  listBook[100];
	P1 listPhieuMuon[100];
	P2 phieuTra[100];
	int n, m, n1, dem = 0, x = 0, h = 0, checkSach[100];
	char ISBNSachMuon[100][50];
	
	
	cout << "\t\t*************************CHUONG TRINH QUAN LY THU VIEN********************************\n\n\n";
	int choice;
	int choice1;
	docFileDG(listDG, n);
	docFileSach(listBook,m);
	while (1 < 2)
	{
		cout << "*******************************************************|      |*********************************************************\n";
		cout << "**\t\t\t\t\t<1> - quan ly doc gia\t\t\t\t\t\t\t      **";
		cout << "\n**\t\t\t\t\t<2> - quan ly sach\t\t\t\t\t\t\t      **";
		cout << "\n**\t\t\t\t\t<3> - lap phieu muon tra\t\t\t\t\t\t      **";
		cout << "\n**\t\t\t\t\t<4> - cac thong ke co ban\t\t\t\t\t\t      **";
		cout << "\n**\t\t\t\t\t<0> - ket thuc chuong trinh\t\t\t\t\t\t      **";

		cout << "\n************************************************************************************************************************";
		cout << "\n\t\t\t\t\t ----->chon chuc nang:\t";
		cin >> choice;
		if (choice == 0)
		{
			cout << "\n\t\t\t\t\t\t* BYE BYE *";
			break;
		}
		else if (choice == 1)
		{
			cout << "\n \t\t\t\t\t\tQUAN LY DOC GIA\n";
			while (1 < 2)
			{
				cout << "\n************************************************************************************************************************";
				cout << "\n<1> - them doc gia";
				cout << "\n<2> - xem danh sach doc gia trong thu vien";
				cout << "\n<3> - chinh sua thong tin mot doc gia";
				cout << "\n<4> - xoa thong tin mot doc gia";
				cout << "\n<5> - tim thong tin doc gia theo so CMND";
				cout << "\n<6> - tim doc gia theo ten";
				cout << "\n<0> - quay lai";
				cout << "\n************************************************************************************************************************";
				cout << "\n chon chuc nang:\t";
				cin >> choice1;
				{
					if (choice1 == 0)
						break;
					else if (choice1 == 1)
					{
						cout << "\n\t\t\t___________________THEM DANH SACH DOC GIA___________________\n";
						cout << "\n\nNhap so doc gia muon nhap: ";
						cin >> n1;
						nhapDSDG(listDG, n1, n);
						saveFileDG(listDG, n);
					}
					else if (choice1 == 2)
					{
						xuatListDG(listDG, n);
					}
					else if (choice1 == 3)
					{
						editDG(listDG, n);
					}
					else if (choice1 == 4)
					{
						delDG(listDG, n);
						saveFileDG(listDG, n);
					}
					else if (choice1 == 5)
					{
						char search[100];
						cin.ignore(1);
						cout << "\t\t+nhap so CMND can tim ";
						gets_s(search);
						searchCMND(listDG, n, search);
					}
					else if (choice1 == 6)
					{
						char search[100];
						cin.ignore(1);
						cout << "\t\t+nhap ten doc gia can tim ";
						gets_s(search);
						searchName(listDG, n, search);
					}
				}
			}
		}
		else if (choice == 2)
		{
			while (1 < 2)
			{
				cout << "\n************************************************************************************************************************";
				cout << "\n<1> -them sach";
				cout << "\n<2> -  xem danh sach cac sach trong thu vien";
				cout << "\n<3> - chinh sua thong tin mot cuon sach";
				cout << "\n<4> - xoa thong tin sach";
				cout << "\n<5> - tim kiem sach theo ISBN";
				cout << "\n<6> - tim kiem sach theo ten sach";
				cout << "\n<0> - quay lai";
				cout << "\n************************************************************************************************************************";
				cout << "\n chon chuc nang:\t";
				cin >> choice1;
				if (choice1 == 0)
				{
					break;
				}
				else if (choice1 == 1)
				{
					cout << "\n\t\t\t___________________THEM DANH SACH SACH___________________\n";
					nhapDSSach(listBook, m);
					saveFileSach(listBook, m);
				}
				else if (choice1 == 2)
				{
					xuatListSach(listBook, m);
					
				}
				else if (choice1 == 3)
				{
					cout << m<<endl;
					editBook(listBook, m);
				}
				else if (choice1 == 4)
				{
					delBook(listBook, m);
					saveFileSach(listBook, m);
				}
				else if (choice1 == 5)
				{
					char search[100];
					cin.ignore(1);
					cout << "\t\t+nhap ma ISBN can tim ";
					gets_s(search);
					searchISBN(listBook, m, search);
				}
				else if (choice1 == 6)
				{
					char search[100];
					cin.ignore(1);
					cout << "\t\t+nhap ten sach can tim ";
					gets_s(search);
					searchNameBook(listBook, m, search);
				}
			}
		}
		else if (choice == 3)
		{
			while (1)
			{
				cout << "\n=====================> MENU TUY CHON LAP PHIEU MUON TRA <=====================\n";
				cout << "\t+ <0>:Thoat lap phieu .\n";
				cout << "\t+ <1>:Lap phieu muon sach.\n";
				cout << "\t+ <2>:Lap phieu tra sach.\n";
				cout << "===============================================================================\n";
				int choice;
				cout << "\nChon chuc nang so: ";
				cin >> choice;
				if (choice == 0)
				{
					break;
				}
				else if (choice == 1)
				{
					nhapListPhieuMuon(listPhieuMuon, dem, x, ISBNSachMuon);
					thoiGianTraDuKien(listPhieuMuon, x);
					xuatPhieuMuon(listPhieuMuon, x, ISBNSachMuon);
				}
				else if (choice == 2)
				{
					nhapPhieuTra(x, checkSach, listPhieuMuon, h, phieuTra, ISBNSachMuon);
					thoiGianTraDuKien(listPhieuMuon, x);
					xuatPhieuTra(x, checkSach, listPhieuMuon, ISBNSachMuon, h, listBook, phieuTra, m);
				}
				
			}
		}
		else if (choice == 4)// cac thong ke
				{
				while (1)
				{
					cout << "\n********************************************* MENU THONG KE **********************************************************\n";
					cout << "*\t <1>:Thong ke so luong sach co trong thu vien.                                                                *" << endl;
					cout << "*\t <2>:Thong ke sach theo the loai.                                                                             *" << endl;
					cout << "*\t <3>:Thong ke so luong doc gia.                                                                               *" << endl;
					cout << "*\t <4>:Thong ke so luong doc gia theo gioi tinh.                                                                *" << endl;
					cout << "*\t <5>:Thong ke sach dang muon.                                                                                 *" << endl;
					cout << "*\t <6>:Thong ke danh sach doc gia bi tre han                                                                    *" << endl;
					cout << "*\t <0>:Quay lai.                                                                                                *" << endl;
					cout << "***********************************************************************************************************************" << endl;


					int choice;
					cout << "\nChon chuc nang so: ";
					cin >> choice;
					if (choice == 0)
						break;
					else if (choice == 1)
					{
						int tk = thongKeSLSach(listBook, m);
						cout << "So luong sach co trong thu vien la: " << tk << endl;
					}
					else if (choice == 2)
					{
						thongKeSachTheoTheLoai(listBook, m);
					}
					else if (choice == 3)
					{
						cout << "So luong doc gia la " << n;
					}
					else if (choice == 4)
					{
						thongKeDGTheoGioiTinh(listDG, n);
					}
					else 	if (choice == 5)
					{
						cout << "So luong sach dang muon " << dem;
					}
					else	if (choice == 6)
					{
						int tk = thongKeDGTreHan(x, listPhieuMuon, phieuTra);
						cout << "So luong doc gia tra sach tre han " << tk << endl;
					}
				}
				}
	}
	return 0;
}