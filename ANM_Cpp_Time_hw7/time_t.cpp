#include "time_t.h"
int My_time::hhh = 24;

void My_time::Converter_h()
{
	bool n;
	cout << "Сейчас стоит " << hhh << " часовой формат времени." << endl;
	cout << "1 - Перевести в 12 часовой формат" << endl;
	cout << "0 - Перевести в 24 часовой формат" << endl;
	cout << "Enter: "; cin >> n; cout << endl;
	if (n)
	{
		hhh = 12;
	}
	else
	{
		hhh = 24;
	}
}

int My_time::Converter_s(My_time _t)
{
	int _s = 0;
	_s = (_t.hh * 3600) + (_t.mm * 60) + _t.ss;
	return _s;
}

My_time Converter_h_m_s(int _s)
{
	My_time _t;
	_t.mm = _s / 60;
	_t.hh = _t.mm / 60;
	_t.ss = _s % 60;
	_t.mm %= 60;

	return _t;
}

ostream& operator<<(ostream& os, My_time& t)//Проверить с конвертером 12-24
{
	int d1 = 0;

	if (t.hh<0||t.hh<0||t.ss<0)
	{
		os<<t.Converter_s(t) << " Секунд"<<endl;
	}
	else
	{
		while (t.hh > t.hhh)
		{
			if (t.hhh == 24)
			{
				t.hh -= t.hhh;
				t.dd++;
			}
			else
			{
				t.hh -= t.hhh;
				d1++;
			}
		}
		if (t.hhh == 12)t.dd = d1 / 2;

		if (t.dd > 0)os << t.dd << " Day, ";
		os << ((t.hh < 10 && t.hh>0) ? "0" : "") << t.hh << ":"
			<< ((t.mm < 10 && t.mm>0) ? "0" : "") << t.mm << ":"
			<< ((t.ss < 10 && t.ss>0) ? "0" : "") << t.ss;
	}	
	return os;
}

istream& operator>>(istream& is, My_time& t)
{
	bool n;
	do
	{
		system("cls");
		cout << "Часы: "; is >> t.hh;
		cout << "Минуты: "; is >> t.mm;
		cout << "Секунды: "; is >> t.ss; cout << endl;
		if (t.hh<0 || t.hh>t.hhh || t.mm < 0
			|| t.mm>60 || t.ss < 0 || t.ss>60)
		{
			cout << "Введены не коррктные данные." << endl;
			cout << "Возобновить ввод?" << endl;
			cout << "1 - Да\n0 - Нет" << endl;
			cout << "Enter: "; is >> n;
		}
		else n = 0;
	} while (n);
	return is;
}

My_time My_time::operator+(My_time _t)
{
	My_time _tt;
	int _ss1, _ss2, sum;
	_ss1 = Converter_s(_t);
	_ss2 = Converter_s(*this);
	sum = _ss1 + _ss2;
	_tt = Converter_h_m_s(sum);
	cout << *this; cout << " + "; cout << _t; cout << " = "; cout << _tt;
	return _tt;
}

My_time My_time::operator-(My_time _t)
{
	My_time _tt;
	int _ss1, _ss2, m;
	_tt.hh = hh - _t.hh;
	_tt.mm = mm - _t.mm;
	_tt.ss = ss - _t.ss;

	m = Converter_s(_tt);
	_tt = Converter_h_m_s(m);
	cout << *this; cout << " - "; cout << _t; cout << " = "; cout << _tt;
	return _tt;
}

My_time My_time::operator*(My_time _t)
{
	My_time _tt;
	int _ss1, _ss2, m;
	_tt.hh = hh * _t.hh;
	_tt.mm = mm * _t.mm;
	_tt.ss = ss * _t.ss;

	m = Converter_s(_tt);
	_tt = Converter_h_m_s(m);
	cout << *this; cout << " * "; cout << _t; cout << " = "; cout << _tt;
	return _tt;
}

My_time My_time::operator/(My_time _t)
{
	My_time _tt;
	int _ss1, _ss2, m;
	_ss1 = Converter_s(*this);
	_ss2 = Converter_s(_t);
	cout <<endl<< _ss1 << " сек.  " << _ss2 << " сек." << endl;
	if (_ss1>_ss2)
	{
		while (_ss2>240)
		{
			_ss1 -= 60;
			_ss2 -= 60;
		}
		cout << *this << " > " << _t << endl;
		m = _ss1 / _ss2;
		cout << _ss1 << " / " << _ss2 << " = "<<m<<endl;
	}
	else if (_ss1 < _ss2)
	{
		while (_ss1 > 240)
		{
			_ss1 -= 60;
			_ss2 -= 60;
		}
		cout << _t << " > " << *this << endl;
		m = _ss2 / _ss1;
		cout << _ss2 << " / " << _ss1 <<" = "<<m<< endl;
	}
	_tt = Converter_h_m_s(m);
	cout <<endl<< _tt<<endl;
	return _tt;
} 

My_time My_time::operator%(My_time _t)
{

	My_time _tt;
	int _ss1, _ss2, m;
	_ss1 = Converter_s(*this);
	_ss2 = Converter_s(_t);
	cout << endl << _ss1 << " сек.  " << _ss2 << " сек." << endl;
	if (_ss1 > _ss2)
	{
		//while (_ss2 > 240)
		//{
		//	_ss1 -= 60;
		//	_ss2 -= 60;
		//}
		cout << *this << " > " << _t << endl;
		m = _ss1 % _ss2;
		cout << _ss1 << " % " << _ss2 << " = " << m << endl;
	}
	else if (_ss1 < _ss2)
	{
		//while (_ss1 > 240)
		//{
		//	_ss1 -= 60;
		//	_ss2 -= 60;
		//}
		cout << *this << " < " << _t << endl;
		m = _ss2 % _ss1;
		cout << _ss2 << " % " << _ss1 << " = " << m << endl;
	}
	_tt = Converter_h_m_s(m);
	cout << endl << _tt << endl;
	return _tt;
}

My_time My_time::operator*(int _n)
{
	int _ss1, m;
	_ss1 = Converter_s(*this);
	m = _ss1 *_n;
	cout << *this;
	*this = Converter_h_m_s(m);
	cout << " * "; cout << _n; cout << " = "; cout << *this;
	return *this;
}

bool My_time::operator>(My_time _t)
{
	int ss1 = Converter_s(*this);
	int ss2 = Converter_s(_t);
	cout << *this; cout << " > "; cout << _t<<endl;
	if (ss1>ss2)
	{
		cout << "True" << endl;
	}
	else cout<<"False"<<endl;
	return ss1>ss2;
}

bool My_time::operator<(My_time _t)
{
	int ss1 = Converter_s(*this);
	int ss2 = Converter_s(_t);
	cout << *this; cout << " < "; cout << _t << endl;
	if (ss1 < ss2)
	{
		cout << "True" << endl;
	}
	else cout << "False" << endl;
	return ss1 < ss2;
}

bool My_time::operator==(My_time _t)
{
	int ss1 = Converter_s(*this);
	int ss2 = Converter_s(_t);
	cout << *this; cout << " == "; cout << _t << endl;
	if (ss1 == ss2)
	{
		cout << "True" << endl;
	}
	else cout << "False" << endl;
	return ss1 == ss2;
}

bool My_time::operator!=(My_time _t)
{
	int ss1 = Converter_s(*this);
	int ss2 = Converter_s(_t);
	cout << *this; cout << " > "; cout << _t << endl;
	if (ss1 != ss2)
	{
		cout << "True" << endl;
	}
	else cout << "False" << endl;
	return ss1 != ss2;
}

My_time My_time::operator++(int n)
{
	ss++;
	if (ss > 59)
	{
		ss = 0;
		mm++;
		if (mm > 59)
		{
			mm = 0;
			hh++;
			if (hh == hhh)
			{
				Reset(*this);
			}
		}
	}
	return *this;
}

My_time My_time::operator--(int n)
{

	if (ss == 0 && mm > 0)
	{
		ss = 59;
		mm--;
		if (mm < 1 && hh > 0)
		{
			mm = 59;
			hh--;
		}
	}

	else if (ss > 0)
	{
		ss--;
		if (ss == 0 && mm > 0)
		{
			ss = 59;
			mm--;
			if (mm < 1 && hh > 0)
			{
				mm = 59;
				hh--;
			}
		}
	}
	else
	{
		Reset(*this);
	}
	return *this;
}

void menu()
{
	My_time t1(5, 45, 7);
	My_time t2(22,58,58);
	My_time res;
	int key=0;
	bool key_1 = 1;
	do
	{
		key_1 = 1;
		system("cls");
		choice_1();
		cout << "Enter: "; cin >> key;
		switch (key)
		{
		case 1:
		{
			cin >> t1;
			cin >> t2;
		}
		break;
		case 2:
		{
			cout << t1 << endl << t2 << endl;
			_getch();
		}
		break;
		case 3:
		{
			My_time::Converter_h();
		}
		break;
		case 4:
		{
			do
			{
				system("cls");
				choice_2();
				cout << t1 << "  " << t2 << endl; 
				cout << "Enter: "; cin >> key;

				if(key==1)
				{
					res = t1 + t2;
					_getch();
				}
				else if (key == 2)
				{
					res = t1 - t2;
					_getch();
				}
				else if (key == 3)
				{
					res = t1 * t2;
					_getch();
				}
				else if (key == 4)
				{
					res = t1 / t2;
					_getch();
				}
				else if (key == 5)
				{
					res = t1 % t2;
					_getch();
				}
				else if (key == 6)
				{
					int n;
					cout << "Введите число: "; cin >> n;
					res = t1 * n;
					_getch();
				}
				else if (key == 0)
				{
					key_1 = 0;
				}

			} while (key_1);
			key_1 = 1;
		}
		break;
		case 5:
		{
			do
			{
				system("cls");				
				choice_3();
				cout << t1 << "  " << t2 <<endl;
				cout << "Enter: "; cin >> key;

				if (key==1)
				{
					t1 > t2;
					_getch();
				}
				else if (key == 2)
				{
					t1 < t2;
					_getch();
				}
				else if (key == 3)
				{
					t1 == t2;
					_getch();
				}
				else if (key == 4)
				{
					t1 != t2;
					_getch();
				}
				else if (key == 0)
				{
					key_1 = 0;
				}

			} while (key_1);
			key_1 = 1;
		}
		break;
		case 6:
		{
			do
			{
				system("cls");
				cout << "1 - Инкремент;" << endl;
				cout << "2 - Дикремент;" << endl;
				cout << "0 - В предыдущее меню;" << endl;
				cout << t1 << endl;
				cout << t2 << " "; cin >> key;
				
				if (key ==1)
				{
					while (!_kbhit())
					{
						t1++;
						cout << t1;
						Sleep(200);
						system("cls");
					}
				}
				else if (key == 2)
				{
					while (!_kbhit())
					{
						t1--;
						cout << t1;
						Sleep(200);
						system("cls");
						if (t1.Converter_s(t1)==0)
							break;
					}
				}
				else if (key == 0)
				{
					key_1 = 0;
				}

			} while (key_1);
			key_1 = 1;
			
		}
		break;

		case 0:
		{
			key_1 = 0;
		}
		break;

		default:
			break;
		}

	} while (key_1);
	cout << "\n\t\t\tThe end" << endl; Sleep(500);
}

void choice_1 ()
{
	cout << "Выберите из нижеперечисленного:" << endl;
	cout << "1 - Задать время;" << endl;
	cout << "2 - Вывести на экран;" << endl;
	cout << "3 - Преобразование времеи;" << endl;
	cout << "Операции:" << endl;
	cout << "4 - Орифметичевкие;" << endl;
	cout << "5 - Логичеcкие;" << endl;
	cout << "6 - Унарные;" << endl << endl;
	cout << "0 - Выход;" << endl << endl;
}

void Reset(My_time _t)
{
	_t.dd = 0;
	_t.hh = 0;
	_t.mm = 0;
	_t.ss = 0;
}

void choice_3()
{
	cout << "1 - '>';" << endl;
	cout << "2 - '<';" << endl;
	cout << "3 - '==';" << endl;
	cout << "4 - '!=';" << endl << endl;
	cout << "0 - В предыдущее меню;" << endl << endl;
}
void choice_2()
{
	cout << "1 - '+';" << endl;
	cout << "2 - '-';" << endl;
	cout << "3 - '*';" << endl;
	cout << "4 - '/';" << endl;
	cout << "5 - '%';" << endl;
	cout << "6 - '*n';" << endl << endl;
	cout << "0 - В предыдущее меню;" << endl << endl;
}