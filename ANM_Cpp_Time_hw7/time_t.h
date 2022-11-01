#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <conio.h>

using namespace std;

class My_time
{
	static int hhh;
	int dd;
	int hh;
	int mm;
	int ss;
public:
	My_time(int _hh, int _mm, int _ss)
	{
		hh = _hh; mm = _mm; ss = _ss; 
	}
	My_time()
	{
		hh = 0; mm = 0;	ss = 0; 
		dd = 0;
	}

	static void Converter_h();

	friend ostream &operator <<(ostream& os, My_time& t);
	friend istream& operator >>(istream& is, My_time& t);
	int Converter_s(My_time _t);
	friend My_time Converter_h_m_s( int _s);

	My_time operator +(My_time _t);
	My_time operator -(My_time _t);
	My_time operator *(My_time _t);
	My_time operator /(My_time _t);
	My_time operator %(My_time _t);
	My_time operator *(int _n);

	bool operator > (My_time _t);
	bool operator <(My_time _t);
	bool operator == (My_time _t);
	bool operator != (My_time _t);

	My_time operator ++(int n);
	My_time operator --(int n);
	friend void Reset(My_time _t);
};

void menu();
void choice_1();
void choice_2 ();
void choice_3();
void pr_2(bool n);
