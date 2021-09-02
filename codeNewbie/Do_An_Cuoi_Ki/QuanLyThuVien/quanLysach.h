#ifndef quanlySach_h
#define quanlySach_h

void danhSachSach(int n,int nBer[], char ISBN[][100], char tenSach[][50], char tacGia[][50], char nhaXB[][20], int namXB[],
	char theLoai[][30], int giaSach[], int soQuyenSach[]);

void themSach(int &n,int nBer[], char ISBN[][100], char tenSach[][50], char tacGia[][50], char nhaXB[][20], int namXB[],
	char theLoai[][30], int giaSach[], int soQuyenSach[]);

void xoaSach(int k, int& n,int nBer[], char ISBN[][100], char tenSach[][50], char tacGia[][50], char nhaXB[][20], int namXB[],
	char theLoai[][30], int giaSach[], int soQuyenSach[]);

void timSachTheoISBN(int n, int nBer[], char ISBN[][100], char tenSach[][50], char tacGia[][50], char nhaXB[][20], int namXB[],
	char theLoai[][30], int giaSach[], int soQuyenSach[]);

void timSachTheoTen(int n, int nBer[], char ISBN[][100], char tenSach[][50], char tacGia[][50], char nhaXB[][20], int namXB[],
	char theLoai[][30], int giaSach[], int soQuyenSach[]);

void edit(int k, int nBer[], char ISBN[][100], char tenSach[][50], char tacGia[][50], char nhaXB[][20], int namXB[],
	char theLoai[][30], int giaSach[], int soQuyenSach[]);

void xemThongTinSachDaSua(int k, int nBer[], char ISBN[][100], char tenSach[][50], char tacGia[][50], char nhaXB[][20], int namXB[],
	char theLoai[][30], int giaSach[], int soQuyenSach[]);
#endif 