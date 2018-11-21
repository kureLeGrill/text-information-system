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

	Product(); // ������� �����������

	Product(string name, int amount, int price, char type); // ������������������ �����������

	~Product(); // ����������

	Product(const Product &n); //copy �����������

	Product operator=(const Product &k);//�������� ����������

string GetName();
void SetName(string n);

int GetAmount();
void SetAmount(int a);

int GetPrice();
void SetPrice(int p);

char GetType();
void SetType(char t);
};
