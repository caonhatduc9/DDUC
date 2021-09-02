#ifndef _QLPhieu_h
#define _QLPhieu_h

void nhapPhieuMuon(char maSoMuon[][25], char ISBNSachMuon[][50], int ngayMuon[100], int thangMuon[100], int namMuon[100], int soLuong[], int &dem, int& n);
int soNgayTrongThang(int thang, int nam);
int khoangCachNgay(int ngay1, int thang1, int nam1, int ngay2, int thang2, int nam2);
void thoiGianTraDuKien(int ngayMuon[], int thangMuon[], int namMuon[], int ngayTra[], int thangTra[], int namTra[], int n);

void xuatPhieuMuon(int n, int soLuong[], char maSoMuon[][25], char ISBNSachMuon[100][50], int ngayMuon[], int thangMuon[],
	int namMuon[], int ngayTra[], int thangTra[], int namTra[]);

void nhapPhieuTra(int n, int checkSach[100], int soLuong[], char maSoMuon[][25], char ISBNSachMuon[100][50], int& h, char maSoTra[][25], int ngayTraTT[], int thangTraTT[], int namTraTT[]);
int tinhTienPhat(int n,int ngayTra[], int thangTra[], int namTra[], int ngayTraTT[], int thangTraTT[], int namTraTT[]);
void xuatPhieuTra(int checkSach[100], int n, char maSoMuon[][25], char maSoTra[][25], int ngayMuon[], int thangMuon[], int namMuon[], int ngayTra[], int thangTra[], int namTra[],
	int ngayTraTT[], int thangTraTT[], int namTraTT[], int soLuong[], char ISBNSachMuon[][50], int h, int giaSach[]);

#endif
