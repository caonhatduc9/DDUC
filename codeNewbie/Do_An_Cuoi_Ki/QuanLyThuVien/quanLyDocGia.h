#ifndef quanlyDocGia_h
#define quanlyDocGia_h
void ngayLapThe(int d, int m, int y);
//danh sach doc gia
void danhSachDocGia(int n, int maSoDG[], char hoTenDG[][70], char CMNDDG[][10], char ngaySinhDG[][15], int gioiTinhDG[], char emailDG[][100],
	char diaChiDG[][300], int ngayLap[], int thangLap[], int namLap[]);
	//xoa thong tin doc gia
	void xoaDocGia(int k, int& n, int maSoDG[], char hoTenDG[][70], char CMNDDG[][10], char ngaySinhDG[][15], int gioiTinhDG[], char emailDG[][100],
		char diaChiDG[][300], int ngayLap[], int thangLap[], int namLap[]);
//them doc gia
	void themDocGia(int& n, int maSoDG[], char hoTenDG[][70], char CMNDDG[][10], char ngaySinhDG[][15], int gioiTinhDG[], char emailDG[][100],
		char diaChiDG[][300], int ngayLap[], int thangLap[], int namLap[]);
	//tim kiem doc gia theo CMND
	void timDGTheoCMND(int n, int maSoDG[], char hoTenDG[][70], char CMNDDG[][10], char ngaySinhDG[][15], int gioiTinhDG[], char emailDG[][100],
		char diaChiDG[][300], int ngayLap[], int thangLap[], int namLap[]);
	//tim kiem doc gia theo ten
	void timDGTheoTen(int n, int maSoDG[], char hoTenDG[][70], char CMNDDG[][10], char ngaySinhDG[][15], int gioiTinhDG[], char emailDG[][100],
		char diaChiDG[][300], int ngayLap[], int thangLap[], int namLap[]);
	//chinh sua htong tin doc gia theo ma so doc gia
	void editDG(int k, int maSoDG[], char hoTenDG[][70], char CMNDDG[][10], char ngaySinhDG[][15], int gioiTinhDG[], char emailDG[][100],
		char diaChiDG[][300], int ngayLap[], int thangLap[], int namLap[]);
		//xem thong tin doc gia sau khi da chinh sua
	void xemThongTinDocGiaDaSua(int k, int maSoDG[], char hoTenDG[][70], char CMNDDG[][10], char ngaySinhDG[][15], int gioiTinhDG[], char emailDG[][100],
		char diaChiDG[][300], int ngayLap[], int thangLap[], int namLap[]);


#endif // !quanlyDocGia_h

