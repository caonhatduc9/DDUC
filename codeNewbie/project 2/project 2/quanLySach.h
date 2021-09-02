#ifndef _sach_h
#define _sach_h
struct book
{
	char ISBN[100];
	char tenSach[100];
	char tacGia[100];
	char nhaXB[100];
	int namXB;
	char theLoai[100];
	int giaSach;
	int soQuyenSach;
};
void nhapSach(book &b);
void nhapDSSach(book listBook[], int &m);
void xuatSach(book bb);
void xuatListSach(book listBook[], int m);
void saveFileSach(book listBook[], int m);
void docFileSach(book listBook[], int& m);
void editBook(book listBook[], int m);
void delBook(book listBook[], int& m);
void searchISBN(book listBook[], int m, char search[]);
void searchNameBook(book listBook[], int m, char search[]);
#endif
