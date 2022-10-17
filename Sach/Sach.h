#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Sach {
	string masach, tensach, tacgia, nhaxuatban, namphathanh, ngaynhapkho;
	long giaban;
	short sotrang, tinhtrangsach;
public:
	string getMasach();
	string getTensach();
	string getTacgia();
	string getNhaxuatban();
	string getNamphathanh();
	string getNgaynhapkho();
	long getGiaban();
	short getSotrang();
	short getTinhtrangsach();

	void setMasach(string _masach);
	void setTensach(string _tensach);
	void setTacgia(string _tacgia);
	void setNhaxuatban(string _nhaxuatban);
	void setNamphathanh(string _namphathanh);
	void setNgaynhapkho(string _ngaynhapkho);
	void setGiaban(long _giaban);
	void setSotrang(short _sotrang);
	void setTinhtrangsach(short _tinhtrangsach);

	Sach(string _masach = "", string _tensach = "", string _tacgia = "", string _nhaxuatban = "", long _giaban = 0, string _namphathanh = "", short _sotrang = 0, string _ngaynhapkho = "", short _tinhtrangsach = 0);
	Sach(const Sach& s);
	~Sach();

	friend istream& operator >> (istream& in, Sach& s);
	friend ostream& operator << (ostream& out, Sach s);

};

struct node {
	Sach data;
	struct node* pNext;
};
typedef struct node NODE;
