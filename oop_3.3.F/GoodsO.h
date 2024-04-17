//////////////////////////////////////////////////////////////////////////////
// GoodsO.h
// заголовочний файл Ц визначенн€ класу
#pragma once
#include <iostream>
#include "Money.h"
using namespace std;
class GoodsO :
	public Money
{
	string name;
	int price, quantity, no, date;

	Money money;
public:
	string GetName() const { return name; };
	int GetDate() const { return date; };
	int GetPrice() const { return price; };
	int GetQuantity() const { return quantity; };
	int GetNo() const { return no; };
	void SetName(string value) { name = value; };
	void SetDate(int value) { date = value; };
	void SetPrice(int value) { price = value; };
	void SetQuantity(int value) { quantity = value; };
	void SetNo(int value) { no = value; }
	void SetMoney(Money value)
	{
		money.SetHr(value.GetHr());
		money.SetKop(value.GetKop());
	}

	GoodsO();
	GoodsO(double, double, string, int, int, int, int);
	GoodsO(const GoodsO&);
	GoodsO& operator = (const GoodsO& s);

	friend Money operator +(const Money& that, const Money& other);
	friend Money operator -(const Money& that, const Money& other);
	friend double operator /(const Money& that, const Money& other);
	friend Money operator /(const Money& that, double division);
	friend Money operator *(const Money& that, double mult);

	GoodsO& operator<<(double newPrice);
	GoodsO& operator+(double amount);
	GoodsO& operator-(double amount);
	GoodsO& operator+(const GoodsO& money);

	GoodsO& operator ++();
	GoodsO& operator --();
	GoodsO operator ++(int);
	GoodsO operator --(int);

	operator string () const;
	friend ostream& operator <<(ostream& out, const GoodsO& x);
	friend istream& operator >>(istream& in, GoodsO& x);
	~GoodsO() { };
};
