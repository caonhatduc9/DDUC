#include"quanLyDocGia.h"
#include"quanLySach.h"
#include"phieuMuonTraSach.h"
#include"thongKe.h"
#include<string.h>
#include<iostream>
using namespace std;

int main()
{
	//du lieu doc gia
	int soLuongDG = 6;
	int maSoDG[100];
	char hoTenDG[100][70];
	char CMNDDG[100][10];
	char ngaySinhDG[100][15];
	int gioiTinhDG[100];
	char emailDG[100][100];
	char diaChiDG[100][300];
	int ngayLap[100];
	int thangLap[100];
	int namLap[100];

	maSoDG[0] = 1;
	strcpy_s(hoTenDG[0], "Cao Nhat Duc");
	strcpy_s(CMNDDG[0], "285771241");
	strcpy_s(ngaySinhDG[0], "10/07/2002");
	gioiTinhDG[0] = 1;
	strcpy_s(emailDG[0], "caonhatduc9@gmail.com");
	strcpy_s(diaChiDG[0], "150/6/9 Long Phuoc");
	ngayLap[0] = 1, thangLap[0] = 1, namLap[0] = 2020;

	maSoDG[1] = 2;
	strcpy_s(hoTenDG[1], "Phan Tuan Khai");
	strcpy_s(CMNDDG[1], "285771252");
	strcpy_s(ngaySinhDG[1], "12/5/2002");
	gioiTinhDG[1] = 1;
	strcpy_s(emailDG[1], "ptkhai1203@gmail.com");
	strcpy_s(diaChiDG[1], "Binh Tan");
	ngayLap[1] = 2, thangLap[1] = 1, namLap[1] = 2020;

	maSoDG[2] = 3;
	strcpy_s(hoTenDG[2], "Ton That Bach");
	strcpy_s(CMNDDG[2], "285776341");
	strcpy_s(ngaySinhDG[2], "24/5/2002");
	gioiTinhDG[2] = 1;
	strcpy_s(emailDG[2], "ttbach@gmail.com");
	strcpy_s(diaChiDG[2], "HoocMon");
	ngayLap[2] = 3, thangLap[2] = 1, namLap[2] = 2020;

	maSoDG[3] = 4;
	strcpy_s(hoTenDG[3], "Huynh Ngoc Son");
	strcpy_s(CMNDDG[3], "285771741");
	strcpy_s(ngaySinhDG[3], "27/3//2002");
	gioiTinhDG[3] = 1;
	strcpy_s(emailDG[3], "hnson@gmail.com");
	strcpy_s(diaChiDG[3], "Quang Nam");
	ngayLap[3] = 4, thangLap[3] = 1, namLap[3] = 2020;

	maSoDG[4] = 5;
	strcpy_s(hoTenDG[4], "Doan Huu Loc");
	strcpy_s(CMNDDG[4], "285771941");
	strcpy_s(ngaySinhDG[4], "12/4/2002");
	gioiTinhDG[4] = 1;
	strcpy_s(emailDG[4], "lapdoan@gmail.com");
	strcpy_s(diaChiDG[4], "My Tho");
	ngayLap[4] = 5, thangLap[4] = 1, namLap[4] = 2020;

	maSoDG[5] = 6;
	strcpy_s(hoTenDG[5], "Nguyen Dang Manh Tu");
	strcpy_s(CMNDDG[5], "285774271");
	strcpy_s(ngaySinhDG[5], "12/5/2002");
	gioiTinhDG[5] = 1;
	strcpy_s(emailDG[5], "ndmTu@gmail.com");
	strcpy_s(diaChiDG[5], "Quan 7");
	ngayLap[5] = 6, thangLap[5] = 1, namLap[5] = 2020;
	//Du lieu sach
	int soLuongSach = 5;
	int nBer[100];
	char ISBN[100][100];
	char tenSach[100][50];
	char tacGia[100][50];
	char nhaXB[100][20];
	int namXB[100];
	char theLoai[100][30];
	int giaSach[100];
	int soQuyenSach[100];

	nBer[0] = 1;
	strcpy_s(ISBN[0], "1");
	strcpy_s(tenSach[0], "Hacker Ielts: Reading");
	strcpy_s(tacGia[0], "Vien Ngon Ngu Hacker");
	strcpy_s(nhaXB[0], "NXB The Gioi");
	namXB[0] = 2019;
	strcpy_s(theLoai[0], "Sach Hoc Ngoai Ngu");
	giaSach[0] = 184000;
	soQuyenSach[0] = 12;

	nBer[1] = 2;
	strcpy_s(ISBN[1], "2");
	strcpy_s(tenSach[1], "Hacker Ielts: Listening");
	strcpy_s(tacGia[1], "Vien Ngon Ngu Hacker");
	strcpy_s(nhaXB[1], "NXB The Gioi");
	namXB[1] = 2019;
	strcpy_s(theLoai[1], "Sach Hoc Ngoai Ngu");
	giaSach[1] = 184000;
	soQuyenSach[1] = 20;

	nBer[2] = 3;
	strcpy_s(ISBN[2], "3");
	strcpy_s(tenSach[2], "The Power Of Habit");
	strcpy_s(tacGia[2], "Charles Duhigg");
	strcpy_s(nhaXB[2], "Random House Books");
	namXB[2] = 2013;
	strcpy_s(theLoai[2], "Kinh Te");
	giaSach[2] = 172000;
	soQuyenSach[2] = 1;

	nBer[3] = 4;
	strcpy_s(ISBN[3], "4");
	strcpy_s(tenSach[3], "Nha Gia Kim");
	strcpy_s(tacGia[3], "Paulo ");
	strcpy_s(nhaXB[3], "NXB Hoi Nha Van");
	namXB[3] = 2020;
	strcpy_s(theLoai[3], "Sach Hoc Ngoai Ngu");
	giaSach[3] = 61500;
	soQuyenSach[3] = 5;

	nBer[4] = 5;
	strcpy_s(ISBN[4], "5");
	strcpy_s(tenSach[4], "Dac Nhan Tam");
	strcpy_s(tacGia[4], "Dale Carnegie");
	strcpy_s(nhaXB[4], "NXB Tong Hop TPHCM");
	namXB[4] = 2018;
	strcpy_s(theLoai[4], "Tam Ly - Ky Nang Song");
	giaSach[4] = 59000;
	soQuyenSach[4] = 10;
	//du lieu nhap tra sach
	int ngayMuon[100], thangMuon[100], namMuon[100], ngayTra[100], thangTra[100], namTra[100], ngayTraTT[100], thangTraTT[100], namTraTT[100];
	int demSachMuon = 0, n = 0, h = 0;
	int checkSach[100];
	checkSach[0] = 1;
	int soLuong[100], dem = 0;
	char maSoMuon[100][25];
	char ISBNSachMuon[100][50];
	char maSoTra[100][25];

	//du lieu thong ke



	cout << "\t\t*************************CHUONG TRINH QUAN LY THU VIEN********************************\n\n\n";
	int choice;
	int choice1;
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
				cout << "\n<1> - xem danh sach doc gia trong thu vien";
				cout << "\n<2> - them doc gia";
				cout << "\n<3> - chinh sua thong tin mot doc gia";
				cout << "\n<4> - xoa thong tin mot doc gia";
				cout << "\n<5> - tim thong tin doc gia theo so CMND";
				cout << "\n<6> - tim doc gia theo ten";
				cout << "\n<0> - quay lai";
				cout << "\n************************************************************************************************************************";
				cout << "\n chon chuc nang:\t";
				cin >> choice1;
				{
					if (choice1 == 1)// xem danh sach doc gia
					{
						cout << "\n\t\t\t___________________Xem danh sach doc gia___________________\n";
						danhSachDocGia(soLuongDG, maSoDG, hoTenDG, CMNDDG, ngaySinhDG, gioiTinhDG, emailDG, diaChiDG, ngayLap, thangLap, namLap);
						break;
					}
					else	if (choice1 == 2)// them doc gia
					{
						cout << "\n Them doc gia";
						themDocGia(soLuongDG, maSoDG, hoTenDG, CMNDDG, ngaySinhDG, gioiTinhDG, emailDG, diaChiDG, ngayLap, thangLap, namLap);
						break;
					}
					else	if (choice1 == 3)// chinh sua thong tin doc gia theo ma so doc gia
					{
						cout << "\nChinh sua thong tin mot doc gia";
						int k;
						cout << "\n\tNhap ma so doc gia muon chinh sua\t";
						cin >> k;
						editDG(k, maSoDG, hoTenDG, CMNDDG, ngaySinhDG, gioiTinhDG, emailDG, diaChiDG, ngayLap, thangLap, namLap);//chinh sua thong tin doc gia theo ma so doc gia
						xemThongTinDocGiaDaSua(k, maSoDG, hoTenDG, CMNDDG, ngaySinhDG, gioiTinhDG, emailDG, diaChiDG, ngayLap, thangLap, namLap);//xem thong tin doc gia do sau khi da chinh sua
						break;
					}
					else if (choice1 == 4)//xao thong tin doc gia theo so thu tu
					{
						int k;
						cout << "\nXoa thong tin mot doc gia";
						do
						{
							cout << "\nChon so thu tu doc gia muon xoa: ";

							cin >> k;
							if (k > soLuongDG || k < 1)
								cout << "\t\t\t\tNhap khong hop le vui long nhap lai..." << endl;
						} while (k > soLuongDG || k < 1);
							xoaDocGia(k, soLuongDG, maSoDG, hoTenDG, CMNDDG, ngaySinhDG, gioiTinhDG, emailDG, diaChiDG, ngayLap, thangLap, namLap);
						//danhSachDocGia(soLuongDG, maSoDG, hoTenDG, CMNDDG, ngaySinhDG, gioiTinhDG, emailDG, diaChiDG, ngayLap, thangLap, namLap);
						break;
					}
					else if (choice1 == 5)//tim kiem thong tin doc gia theo CMND
					{
						cout << "\n5 - tim thong tin doc gia theo so CMND";
						timDGTheoCMND(soLuongDG, maSoDG, hoTenDG, CMNDDG, ngaySinhDG, gioiTinhDG, emailDG, diaChiDG, ngayLap, thangLap, namLap);
						break;
					}
					else if (choice1 == 6)//tim thong tin do gia theo ten
					{
						cout << "\ntim kiem sach theo ho ten:\t";
						timDGTheoTen(soLuongDG, maSoDG, hoTenDG, CMNDDG, ngaySinhDG, gioiTinhDG, emailDG, diaChiDG, ngayLap, thangLap, namLap);
						break;
					}
					else if (choice1 == 0)
					{
						break;
					}
					else
						cout << "\nLua chon khong hop le oop!\n\n";
				}
				break;
			}
		}
		else if (choice == 2)// quan ly sach
		{
			while (1 < 2)
			{
				cout << "\n************************************************************************************************************************";
				cout << "\n<1> - xem danh sach cac sach trong thu vien";
				cout << "\n<2> - them sach";
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
				else if (choice1 == 1)//xem danh sachn trong thu vien
				{
					cout << "Xem Danh Sach Cac Sach" << endl;
					danhSachSach(soLuongSach, nBer, ISBN, tenSach, tacGia, nhaXB, namXB, theLoai, giaSach, soQuyenSach);
				}
				else if (choice1 == 2)// them sach
				{
					themSach(soLuongSach, nBer, ISBN, tenSach, tacGia, nhaXB, namXB, theLoai, giaSach, soQuyenSach);
				}
				else if (choice1 == 4)// xoa thong tin sach theo thu tu
				{
					cout << "\nXoa Thong Tin Sach";
					cout << "\nChon STT Muon Xoa ";
					int k;
					cin >> k;
					if (k > soLuongSach || k < 1)
					{
						cout << endl << "\t\t\t\tLua chon ma sach khong hop le vui long nhap lai..." << endl;
					}
					else
					{
						xoaSach(k, soLuongSach, nBer, ISBN, tenSach, tacGia, nhaXB, namXB, theLoai, giaSach, soQuyenSach);
						cout << "\nDanh Sach Sau Khi Xoa" << endl;
						danhSachSach(soLuongSach, nBer, ISBN, tenSach, tacGia, nhaXB, namXB, theLoai, giaSach, soQuyenSach);
						break;
					}
				}
				else if (choice1 == 5)//tim thong tin sach theo ISBN
				{
					timSachTheoISBN(soLuongSach, nBer, ISBN, tenSach, tacGia, nhaXB, namXB, theLoai, giaSach, soQuyenSach);
				}
				else if (choice1 == 6)//tim thong tin sach theo ten sach
				{
					timSachTheoTen(soLuongSach, nBer, ISBN, tenSach, tacGia, nhaXB, namXB, theLoai, giaSach, soQuyenSach);
					break;
				}
				else if (choice1 == 3)//chinh sua thong tin mot quyen sach
				{
					int stt;
					cout << "\nnhap so thu tu can sua\t";
					cin >> stt;
					if (stt > soLuongSach || stt < 1)
					{
						cout << "NHAP LAI!!!!!!!!" << endl;
					}
					edit(stt, nBer, ISBN, tenSach, tacGia, nhaXB, namXB, theLoai, giaSach, soQuyenSach);
					xemThongTinSachDaSua(stt, nBer, ISBN, tenSach, tacGia, nhaXB, namXB, theLoai, giaSach, soQuyenSach);
					break;
				}
			}
		}
		else if (choice == 3)// lap phieu muon tra sach
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
					nhapPhieuMuon(maSoMuon, ISBNSachMuon, ngayMuon, thangMuon, namMuon, soLuong, demSachMuon, n);
					thoiGianTraDuKien(ngayMuon, thangMuon, namMuon, ngayTra, thangTra, namTra, n);
					xuatPhieuMuon(n, soLuong, maSoMuon, ISBNSachMuon, ngayMuon, thangMuon, namMuon, ngayTra, thangTra, namTra);
					break;
				}
				else if (choice == 2)
				{
					nhapPhieuTra(n, checkSach, soLuong,maSoMuon,ISBNSachMuon, h, maSoTra, ngayTraTT, thangTraTT, namTraTT);
					thoiGianTraDuKien(ngayMuon, thangMuon, namMuon, ngayTra, thangTra, namTra, n);
					xuatPhieuTra(checkSach, n, maSoMuon, maSoTra, ngayMuon, thangMuon, namMuon, ngayTra, thangTra, namTra, ngayTraTT, thangTraTT, namTraTT, soLuong, ISBNSachMuon, h, giaSach);
					break;
				}
				else
				{
					cout << "Chuc nang khong ton tai. Vui long chon chuc nang khac!!";
					break;
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
					int tk = thongKeSLSach(soLuongSach, soQuyenSach);
					cout << "So luong sach co trong thu vien la: " << tk << endl;
				}
				else if (choice == 2)
				{
					thongKeSachTheoTheLoai(soLuongSach, theLoai, soQuyenSach);
				}
				else if (choice == 3)
				{
					cout << "So luong doc gia la " << soLuongDG;
				}
				else if (choice == 4)
				{
					thongKeDGTheoGioiTinh(soLuongDG, gioiTinhDG);
				}
				else 	if (choice == 5)
				{
					cout << "So luong sach dang muon " << demSachMuon;
				}
				else	if (choice == 6)
				{
					int tk = thongKeDGTreHan(n, ngayTra, thangTra, namTra, ngayTraTT, thangTraTT, namTraTT);
					cout << "So luong doc gia tra sach tre han " << tk << endl;
				}
			}
		}
	}
	return 0;
}