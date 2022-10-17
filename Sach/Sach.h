#pragma once
#include<iostream>
#include<string>     //sử dụng để đọc kiểu dữ liệu chuỗi (có khoảng trắng)
#include<fstream>	 //sử dụng để nhập xuất dữ liệu từ file
using namespace std;

// khai báo đối tượng sách
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

	friend istream& operator >> (istream& in, Sach& s);    //nhập sách
	friend ostream& operator << (ostream& out, Sach s);	   //xuất sách

	void doc_1_quyen_sach(ifstream& filein, Sach& s);

	bool operator != (Sach s);
};


//sử dụng danh sách liên kết đơn để quản lí danh sách tất cả các sách trong thư viện

//khai báo cấu trúc node
class LinkedList;

class Node {
	friend LinkedList;
private:
	Sach _data;				//chứa dữ liệu kiểu Sach
	Node* _pNext;     //đây là con trỏ dùng để liên kết các node với nhau
public:
	Node(Sach data);
	void display();
};

//khai báo cấu trúc danh sách liên kết đơn
class LinkedList {
	Node* _pHead;			//node quản lý đầu danh sách
	Node* _pTail;			//node quản lý cuối danh sách
	int _size;
public:
	LinkedList();
	~LinkedList();

	void hienThiThongTinSach();
	void themSach(Sach data);
	void xoaSach(Sach data);
};

