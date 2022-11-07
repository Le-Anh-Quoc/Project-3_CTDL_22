#pragma once
#include<iostream>
#include<string>     //sử dụng để đọc kiểu dữ liệu chuỗi (có khoảng trắng)
#include<fstream>	 //sử dụng để nhập xuất dữ liệu từ file
#include<iomanip>	//su dung cho setw
using namespace std;

// khai báo đối tượng sách
class Sach {
	string masach, tensach, tacgia, nhaxuatban, giaban, namphathanh, sotrang, ngaynhapkho, tinhtrangsach;
public:
	/*string getMasach();
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
	void setTinhtrangsach(short _tinhtrangsach);*/

	Sach(string _masach = "", string _tensach = "", string _tacgia = "", string _nhaxuatban = "", string _giaban = "", string _namphathanh = "", string _sotrang = "", string _ngaynhapkho = "", string _tinhtrangsach = "");
	Sach(const Sach& s);
	~Sach();

	void themSach(Sach& s);
	void cap_nhat_sach(Sach arr[1000], int& n);
	void xoaSach(Sach arr[1000], int& n);
	int TimSach(Sach arr[1000], int sl, string id);

	void xuattitle();
	void xuat();
	void getlist(Sach arr[1000], int& sl);
	void ttsach(Sach arr[1000], int sl, string id, string cd);


	//friend istream& operator >> (istream& in, Sach& s);    //nhập sách
	//friend ostream& operator << (ostream& out, Sach s);	   //xuất sách

	//void doc_1_quyen_sach(ifstream& filein);
	//bool operator != (Sach s);
};


//sử dụng danh sách liên kết đơn để quản lí danh sách tất cả các sách trong thư viện

//khai báo cấu trúc node
class LinkedList;

class Node {
	friend LinkedList;		//cho Linkedlist lam ban voi Node
private:
	Sach item;				//chứa dữ liệu kiểu Sach
	Node* pNext;     //đây là con trỏ dùng để liên kết các node với nhau
public:
	Node(Sach _item);
	void display();
};

//khai báo cấu trúc danh sách liên kết đơn
class LinkedList {
	Node* pHead;			//node quản lý đầu danh sách
	Node* pTail;			//node quản lý cuối danh sách
public:
	LinkedList();
	~LinkedList();

	void hienThiThongTinSach();     //in ra tất cả sách đang có
	void themSach(Sach _item);		//thêm một sách vào đầu danh sách
	void xoaSach(Sach _item);		//xóa một sách với masach bat ki

	void doc_danh_sach_quyen_sach(ifstream& filein); //sadasdasdasdasdasdasdasdsadasdasdasdas
};

