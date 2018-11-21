#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Product
{
private:

	string name;
	int amount;
	int price;
	char type;

public:

	Product(); // обычный конструктор

	Product(string name, int amount, int price, char type); // параметрическиский конструктор

	~Product(); // деструктор

	Product(const Product &n); //copy конструктор

	Product operator=(const Product &k);//оператор пржиразени

string GetName();
void SetName(string n);

int GetAmount();
void SetAmount(int a);

int GetPrice();
void SetPrice(int p);

char GetType();
void SetType(char t);
};
