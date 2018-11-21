#include <iostream>
#pragma once
#include <string>

using namespace std;

class Is
{

private:

	string nameIs;

public:
	Is();

	Is(const Is &n);// вот мой копи конструктор :-)

	Is(string namej);

	~Is();

	Is operator= (const Is &p);

	 int createNewId(string idType);
	 void rewriteId(int newId, string idType, int t);
	 void rewriteId(int newId, string idType);
	 int controlPassword(string password);
	virtual bool checkConfigFile(string filePAth);//функция для эксепшена
};