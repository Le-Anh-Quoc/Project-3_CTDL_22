#pragma once
#include<iostream>
#include<string>     //sử dụng để đọc kiểu dữ liệu chuỗi (có khoảng trắng)
#include<fstream>	 //sử dụng để nhập xuất dữ liệu từ file
#include<iomanip>	//su dung cho setw
#include <ctime>
#include <chrono> 
#include<conio.h>
using namespace std;

class PhieuMuon {
	string soPhieuMuon, maBanDoc, maSach, ngayMuon, ngayTra, tinhTrang;
	string stt;
public:

	PhieuMuon(string _soPhieuMuon = "", string _maBanDoc = "", string _maSach = "", string _ngayMuon = "", string _ngayTra = "", string _tinhTrang = "");
	PhieuMuon(const PhieuMuon& p);
	~PhieuMuon();

	void muonsach(PhieuMuon arr[1000], int& sl, string mabd, string masach);
	string trasach(PhieuMuon arr[1000], int sl, string sp);
	void update_pm(PhieuMuon arr[1000], int n);
	void title_phieumuon();
	void xuat();
	void getlist_pm(PhieuMuon arr[1000], int& sl);
};