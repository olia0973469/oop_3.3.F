//////////////////////////////////////////////////////////////////////////////
// GoodsC.cpp
// פאיכ נואכ³חאצ³¿ – נואכ³חאצ³ÿ לועמה³ג ךכאסף

#include <iostream>
#include <sstream>
#include "GoodsC.h"

using namespace std;

GoodsC::GoodsC()
{
	SetHr(0);
	SetKop(0);
	SetName("");
	SetDate(0);
	SetPrice(0);
	SetQuantity(0);
	SetNo(0);
}

GoodsC::GoodsC(double a, double b, string c, int d, int e, int f, int g)
{
	SetHr(a);
	SetKop(b);
	SetName(c);
	SetDate(d);
	SetPrice(e);
	SetQuantity(f);
	SetNo(g);
}

GoodsC::GoodsC(const GoodsC& p)
{
	SetHr(p.GetHr());
	SetKop(p.GetKop());
	SetName(p.GetName());
	SetDate(p.GetDate());
	SetPrice(p.GetPrice());
	SetQuantity(p.GetQuantity());
	SetNo(p.GetNo());
}

GoodsC& GoodsC::operator = (const GoodsC& s)
{
	Money::operator = (s);
	name = s.name;
	date = s.date;
	price = s.price;
	quantity = s.quantity;
	no = s.no;
	return *this;
}

GoodsC& GoodsC::operator<<(double newPrice)
{
	price = newPrice;
	return *this;
}

GoodsC& GoodsC::operator+(double amount)
{
	quantity += amount;
	return *this;
}

GoodsC& GoodsC::operator-(double amount)
{
	quantity -= amount;
	if (quantity < 0)
		quantity = 0;
	return *this;
}

GoodsC& GoodsC::operator+(const GoodsC& money)
{
	GoodsC result;
	double total = money.GetHr() + (money.GetKop() / 100);
	total *= quantity;
	return result;
}

GoodsC::operator string() const
{
	stringstream ss;
	cout << endl;
	ss << "name = " << name << endl;
	ss << "price = " << price << endl;
	ss << "quantity = " << quantity << endl;
	ss << "no = " << no << endl;
	ss << "date = " << date << endl;
	return Money::operator string() + ss.str();
}

GoodsC& GoodsC::operator ++()
{
	++money;
	return *this;
}

GoodsC& GoodsC::operator --()
{
	--money;
	return *this;
}

GoodsC GoodsC::operator ++(int)
{
	GoodsC tmp = *this;
	this->money++;
	return tmp;
}

GoodsC GoodsC::operator --(int)
{
	GoodsC tmp = *this;
	this->money--;
	return tmp;
}

ostream& operator <<(ostream& out, const GoodsC& x)
{
	out << string(x);
	return out;
}

istream& operator >>(istream& in, GoodsC& s)
{
	string name;
	int price, quantity, no, date;
	cout << endl;
	cout << "name = "; in >> name;
	cout << "price = "; in >> price;
	cout << "quantity = "; in >> quantity;
	cout << "no = "; in >> no;
	cout << "date = "; in >> date;
	s.SetPrice(price);
	s.SetQuantity(quantity);
	s.SetNo(no);
	s.SetDate(date);
	double hr, kop;
	cout << endl;
	cout << "hrn = "; in >> hr;
	cout << "kop = "; in >> kop;
	s.SetHr(hr);
	s.SetKop(kop);
	return in;
}
