#include"Sach.h" // gọi thư viện sach.h đã khai báo ở Header Files

//định nghĩa các hàm trong class Sach
//lấy thông tin về Sách
string Sach::getMasach() { return masach; }
string Sach::getTensach() { return tensach; }
string Sach::getTacgia() { return tacgia; }
string Sach::getNhaxuatban() { return nhaxuatban; }
long Sach::getGiaban() { return giaban; }
string Sach::getNamphathanh() { return namphathanh; }
short Sach::getSotrang() { return sotrang; }
string Sach::getNgaynhapkho() { return ngaynhapkho; }
short Sach::getTinhtrangsach() { return tinhtrangsach; }

//gán thông tin cho sách mới
void Sach::setMasach(string _masach) { masach = _masach; }
void Sach::setTensach(string _tensach) { tensach = _tensach; }
void Sach::setTacgia(string _tacgia) { tacgia = _tacgia; }
void Sach::setNhaxuatban(string _nhaxuatban) { nhaxuatban = _nhaxuatban; }
void Sach::setGiaban(long _giaban) { giaban = _giaban; }
void Sach::setNamphathanh(string _namphathanh) { namphathanh = _namphathanh; }
void Sach::setSotrang(short _sotrang) { sotrang = _sotrang; }
void Sach::setNgaynhapkho(string _ngaynhapkho) { ngaynhapkho = _ngaynhapkho; }
void Sach::setTinhtrangsach(short _tinhtrangsach) { tinhtrangsach = _tinhtrangsach; }

Sach::Sach(string _masach, string _tensach, string _tacgia, string _nhaxuatban, long _giaban, string _namphathanh, short _sotrang, string _ngaynhapkho, short _tinhtrangsach)
{
	masach = _masach;
	tensach = _tensach;
	tacgia = _tacgia;
	nhaxuatban = _nhaxuatban;
	giaban = _giaban;
	namphathanh = _namphathanh;
	sotrang = _sotrang;
	ngaynhapkho = _ngaynhapkho;
	tinhtrangsach = _tinhtrangsach;
}
Sach::Sach(const Sach& s)
{
	masach = s.masach;
	tensach = s.tensach;
	tacgia = s.tacgia;
	nhaxuatban = s.nhaxuatban;
	giaban = s.giaban;
	namphathanh = s.namphathanh;
	sotrang = s.sotrang;
	ngaynhapkho = s.ngaynhapkho;
	tinhtrangsach = s.tinhtrangsach;
}
Sach::~Sach() {}

void Sach::doc_1_quyen_sach(ifstream& filein)
{
	filein >> masach;
	filein.ignore();
	getline(filein, tensach);
	getline(filein, tacgia);
	getline(filein, nhaxuatban);
	filein >> giaban >> namphathanh >> sotrang >> ngaynhapkho >> tinhtrangsach;
}

bool Sach::operator != (Sach s)
{
	if (masach == s.masach) {
		return true;
	}
	return false;
}

istream& operator >> (istream& in, Sach& s)
{
	in >> s.masach;
	cin.ignore();
	getline(in, s.tensach);
	getline(in, s.tacgia);
	getline(in, s.nhaxuatban);
	in >> s.giaban >> s.namphathanh >> s.sotrang >> s.ngaynhapkho >> s.tinhtrangsach;
	return in;
}
ostream& operator << (ostream& out, Sach s)
{
	out << s.masach << " | " << s.tensach << " | " << s.tacgia << " | " << s.nhaxuatban << " | " << s.giaban << " | " << s.namphathanh << " | " << s.sotrang << " | " << s.ngaynhapkho << " | " << s.tinhtrangsach;
	out << endl;
	return out;
}

//định nghĩa các phương thức của Node
Node::Node(Sach _item)
{
	item = _item;
	pNext = NULL;
}
void Node::display()
{
	cout << item;
}


//định nghĩa các phương thức của LinkedList
LinkedList::LinkedList()
{
	pHead = NULL;
	pTail = NULL;
}
LinkedList::~LinkedList(){}
void LinkedList::hienThiThongTinSach()
{
	Node* p = pHead;
	while (p != NULL) 
	{
		p->display();
		p = p->pNext;
	}
}
void LinkedList::themSach(Sach _item)
{
	Node* pAdd = new Node(_item);
	if (pHead == NULL)
	{
		pHead = pTail = pAdd;
	}
	else {
		pAdd->pNext = pHead;
		pHead = pAdd;
	}
}
void LinkedList::xoaSach(Sach _item)
{
	Node* p = pHead, * pTemp = NULL;
	while ((p != NULL) && (p->item != _item))
	{
		pTemp = p;
		p = p->pNext;
	}
	if (p == NULL) return;
	if (pTemp != NULL)
	{
		if (p == pTail) 
		{
			pTail = pTemp;
			pTail->pNext = NULL;
		}
		pTemp->pNext = p->pNext;
		delete p;
	}
}

//void LinkedList::doc_danh_sach_quyen_sach(ifstream& filein)
//{
//	while (!filein.eof()) {
//		Sach s;
//		s.doc_1_quyen_sach(filein);
//		Node* p = new Node(s);
//		themSach(p);
//	}
//}
