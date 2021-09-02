#ifndef phieu_h
#define phieu_h
#include"quanLySach.h"
struct P1
{
    int maSoMuon;
    char ISBNSachMuon[100];
    int ngayMuon;
    int thangMuon;
    int namMuon;
    int ngayTra;
    int thangTra;
    int namTra;
    int soLuong;
};
struct P2
{
    int maSoTra;
    int ngayTraTT;
    int thangTraTT;
    int namTraTT;
};

void nhapPhieuMuon(P1 &p, int& dem, char ISBNSachMuon[100][50]);
void nhapListPhieuMuon(P1 listPhieuMuon[], int& dem, int& x, char ISBNSachMuon[100][50]);
int soNgayTrongThang(int thang, int nam);
int khoangCachNgay(int ngay1, int thang1, int nam1, int ngay2, int thang2, int nam2);
void thoiGianTraDuKien(P1 listPhieuMuon[],  int x);
void xuatPhieuMuon(P1 listPhieuMuon[], int x, char ISBNSachMuon[100][50]);
void nhapPhieuTra(int x, int checkSach[100], P1 listPhieuMuon[], int& h, P2 phieuTra[], char ISBNSachMuon[100][50]);
int tinhTienPhat(int x, P1 ListPhieuMuon[], P2 phieuTra[]);
int  checkPrice(char ISBNSachMuon[][50], int price, int m, book s[]);
void xuatPhieuTra(int x, int checkSach[100], P1 listPhieuMuon[], char ISBNSachMuon[][50], int h, book b[], P2 phieuTra[], int m);
#endif // !phieu_h
