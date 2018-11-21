#include <iostream>
#include "product.h"
#include "users.h"
#include <string>
#pragma once

using namespace std;

class Clients:public User
{

private:

	string name;
	string password;

public:

	Clients();

	Clients(string namej);// ������ ��������������� 

	Clients(string newName, string password);// ������ ��������������� 

	Clients(const Clients &n) ;//copy ����������� (operator= == copyconstructor)<-��������!!!!!!!!

	~Clients();
	
	Clients operator=(const Clients &j);

	string getName();
	void setName(string n);

	Product operator+(string category); //pretezovani operatoru
	void createOrder();
	void showAlOrdersOnClient();
	void removeOrder();
};
