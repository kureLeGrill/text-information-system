#include <string>
#include <iostream>
#include <vector>
#include "is.h"
#pragma once

using namespace std;

class User: public Is // тема наледование дедичность 
{
private:
	
	string login_name;
	

public:

	User(){login_name = "";}; //безпараметрический
	User(string j){login_name = j;};
	~User(){login_name = "";}
	User(const User &j){login_name = j.login_name;}
	User operator=(const User &j);  //переехал в cpp

	int login(string name, string password);
	bool createNewPasswordForNewUser(string login, string password);
	bool createNewPasswordForNewUser(string login, string password, int role); //pretezovani operatoru, функция с таким же названием но с разными параметрами для прияния внутрь
	bool checkPasswordClient(string login, string password);
	bool checkPasswordStuff(string login, string password);
	bool checkNewLogin(string name);
	int controlSymbols(string str);
	
	bool checkConfigFile(string filePAth);

	void showAllCategoryOfProducts();
	vector <string> getAllProductsFromCategory(int categoryNumber);

	void exit_user();
}; 


