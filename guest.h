#pragma once
#include <iostream>
#include "is.h"
#include <string>

using namespace std;

class Guest:public Is {

private :
	
	string name;

public:

	Guest();

	Guest(string jname);

	~Guest();

	Guest(const Guest &h);

	Guest operator=(const Guest &j);

	void registration_new_user(string &newLoginName); //Reference jako parametr funkce a návratová 1 
	void regisgtrationNewPasswordForNewUser(std::string password);	
};

