#include <string>
#include "product.h"

Product::Product()
{
	name = "___";
	amount = 0;
	price = 0;
	type = ' ';
}

Product::Product(string name, int amount, int price, char type)
{
	SetPrice(price);
	SetName(name);
	SetType(type);
	SetAmount(amount);
}

Product::~Product()
{
	name = "";
	amount = 0;
	price = 0;
	type = ' ';
}

Product::Product(const Product &n) //copy конструктор
{
	name = n.name;
	amount = n.amount;
	price = n.price;
	type = n.type;
}

Product Product::operator=(const Product &k)
{
	name = k.name;
	amount = k.amount;
	price = k.price;
	type = k.type;
	return *this;
}

void Product::SetName(string n)
{
	name = n;
}

string Product::GetName()
{
	return name;
}

void Product::SetAmount(int a)
{
	amount = a;
}

int Product::GetAmount()
{
	return amount;
}

void Product::SetPrice(int p)
{
	price = p*amount;
}

int Product::GetPrice()
{ 
	return price;
}

void Product::SetType(char t)
{
	type = t;
}

char Product::GetType()
{

	return type;
}