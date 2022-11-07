#pragma once
#include<iostream>
#include<string>     //sử dụng để đọc kiểu dữ liệu chuỗi (có khoảng trắng)
#include<fstream>	 //sử dụng để nhập xuất dữ liệu từ file
#include<iomanip>
#include<conio.h>
#include<Windows.h>
using namespace std;

string maHoaPassword(size_t length_max);
bool manHinhDangNhap();
void menu();
void remove_scrollbar();