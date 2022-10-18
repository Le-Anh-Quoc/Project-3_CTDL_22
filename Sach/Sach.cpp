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

void Sach::doc_1_quyen_sach(ifstream& filein, Sach& s)
{
	filein >> s;
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
Node::Node(Sach data)
{
	_data = data;
	_pNext = NULL;
}
void Node::display()
{
	cout << _data;
}

//định nghĩa các phương thức của LinkedList
LinkedList::LinkedList()
{
	_pHead = NULL;
	_pTail = NULL;
	_size = 0;
}
LinkedList::~LinkedList(){}
void LinkedList::hienThiThongTinSach()
{
	Node* pWalker = _pHead;
	while (pWalker != NULL) 
	{
		pWalker->display();
		pWalker = pWalker->_pNext;
	}
}
void LinkedList::themSach(Sach data)
{
	Node* pAdd = new Node(data);
	if (_pHead == NULL)
	{
		_pHead = _pTail = pAdd;
	}
	else {
		pAdd->_pNext = _pHead;
		_pHead = pAdd;
	}
	_size++;
}
void LinkedList::xoaSach(Sach data)
{
	Node* pWalker = _pHead, * pTemp = NULL;
	while ((pWalker != NULL) && (pWalker->_data != data))
	{
		pTemp = pWalker;
		pWalker = pWalker->_pNext;
	}
	if (pWalker == NULL) return;
	if (pTemp != NULL)
	{
		if (pWalker == _pTail) 
		{
			_pTail = pTemp;
			_pTail->_pNext = NULL;
		}
		pTemp->_pNext = pWalker->_pNext;
		delete pWalker;
	}
	_size--;
}
