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

	Clients(string namej);// первый параметрический 

	Clients(string newName, string password);// второй параметрический 

	Clients(const Clients &n) ;//copy конструктор (operator= == copyconstructor)<-неправда!!!!!!!!

	~Clients();
	
	Clients operator=(const Clients &j);

	string getName();
	void setName(string n);

	Product operator+(string category); //pretezovani operatoru
	void createOrder();
	void showAlOrdersOnClient();
	void removeOrder();
};
