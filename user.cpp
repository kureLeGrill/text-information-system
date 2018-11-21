#include "users.h"
#include <fstream>
#include "fileHelper.h"
#include <list>
#include <string>

using namespace fileHelper; //вызываю namespace file helper
using namespace std;

User User::operator=(const User &j)
{
	login_name = j.login_name;
	return *this;
}


bool User::checkConfigFile(string pathToFileConfig) // выемка внутри проверяет есть ли в папке config_file() - если файла нет , то не наша папка
{
	fstream configFile;
	string error = "error, is not found";
	cout << "User testing" << endl;
	try// выемка numer uno
	{
		configFile.open(pathToFileConfig + "\\system_config.txt");
		if (configFile.is_open() == false)
		{
			throw error;
		}		
	}
	catch (string e)
	{
		cerr << e << '\n';
		return false;
	}
	return true;
}

int User::login(string name, string password)
{
	//проверяет логин в списке есть или нет

	string wayToFileWithClientLogins = "C:\\Inf.System\\User\\UserListClient.txt";
	string wayToFileWithStiffLogins = "C:\\Inf.System\\User\\UserListStuff.txt";
	string wayToFileWithClientPassswords = "C:\\Inf.System\\User\\Clients\\Passwords.txt";
	string wayToFileWithStuffPassswords = "C:\\Inf.System\\User\\Stuff\\Passwords.txt";

	bool findClient;
	bool findStuff;

	vector<string> names;
	names = doubleFileReader(wayToFileWithClientLogins);
	

	findClient = FindSameLogin(names, name);//сравнили имя в первом файле , теперб будем во втором файле

	if(findClient == true)
	{
		if (checkPasswordClient(name, password) == true)
		{
			return 1;
		}
	}
	names.clear();
	names = doubleFileReader(wayToFileWithStiffLogins);
	findStuff = FindSameLogin(names, name);

	if (findStuff == true)
	{
		if (checkPasswordStuff(name, password) == true)
		{
			return 2;
		}
	}

	return 0;

}

bool User::checkPasswordClient(string login, string password)
{
	ifstream fileWithPasswords;
	fileWithPasswords.open("C:\\Inf.System\\User\\Clients\\Passwords.txt");
	string arrForLogin;
	string arrForPassword;
	string tmpArr;
	bool check = true;
	int semicolCheck = 0;

	while (fileWithPasswords.good())
	{
		string tmp;
		string tmpLogin;
		string tmpPassword;
		fileWithPasswords >> tmp;
		semicolCheck = 0;
		for each  (char c in tmp)
		{
			if (c != ';' && semicolCheck == 0)
			{
				tmpLogin = tmpLogin + c;
			}

			if (c == ';')
			{
				semicolCheck++;
			}

			if (c != ';' && semicolCheck == 1 && login == tmpLogin && c != '-')
			{
				tmpPassword = tmpPassword + c;
			}
		}

		if (password == tmpPassword)
		{
			return true;
		}
	}
	return false;
}

bool User::checkPasswordStuff(string login, string password)
{
	ifstream fileWithPasswords;
	fileWithPasswords.open("C:\\Inf.System\\User\\Stuff\\Passwords.txt");
	string arrForLogin;
	string arrForPassword;
	string tmpArr;
	bool check = true;
	int semicolCheck = 0;

	while (fileWithPasswords.good())
	{
		string tmp;
		string tmpLogin;
		string tmpPassword;
		fileWithPasswords >> tmp;
		semicolCheck = 0;
		for each  (char c in tmp)
		{
			if (c != ';' && semicolCheck == 0)
			{
				tmpLogin = tmpLogin + c;	
			}

			if (c == ';')
			{
				semicolCheck++;
			}
			
			if (c != ';' && semicolCheck == 1 && login == tmpLogin && c != '-')
			{
				tmpPassword = tmpPassword + c;
			}
		}

		if (password == tmpPassword)
		{
			return true;
		}
	}
	return false;
}

bool User::checkNewLogin(string name)
{
	bool findClient;
	string wayToFileWithClientLogins = "C:\\Inf.System\\User\\UserListClient.txt";
	vector<string> names;
	names = doubleFileReader(wayToFileWithClientLogins);

	findClient = FindSameLogin(names, name);//сравнили имя в первом файле , теперб будем во втором файле

	return findClient;

}

int User::controlSymbols(string str) // проверка на запрещенные символы
{
	for each (char h in str)
	{
		if (h == '-')
		{
			return 1;
		}
		if (h == ';')
		{
			return 2;
		}
	}
	return 0;
}

bool User::createNewPasswordForNewUser(std::string login, std::string password)
{
	ofstream totSamyjFaiil;
	totSamyjFaiil.open("C:\\Inf.System\\User\\Clients\\Passwords.txt", ios::app);
	
	if (totSamyjFaiil.is_open())
	{
		totSamyjFaiil << endl  << login << ";"<< password << "-";

	}

	return false;
}

bool User::createNewPasswordForNewUser(std::string login, std::string password, int role)
{
	return true;
}

void User::showAllCategoryOfProducts()
{
	fstream file;
	string path = "C:\\Inf.System\\Products\\ProductCategories.txt";
	list <string> categoryList;
	list<string>::iterator newIteratorForCategory; // предпоследня тема итераторы
	file.open(path);

	if (file.is_open())
	{
		while (file.good())
		{
			std::string tmp;
			file >> tmp;

			categoryList.push_back(tmp);
		}

	}
	file.close();

	for (newIteratorForCategory = categoryList.begin(); newIteratorForCategory != categoryList.end(); newIteratorForCategory++) //тут используюитератор
	{
		cout << *newIteratorForCategory << endl;
	}
}

vector<string> User::getAllProductsFromCategory(int categoryNumber)
{
	
	fstream mobileFile;
	fstream compucterFile;
	fstream ipadFile;
	vector<string> nikolaj;
	
	
	string computersPath = "C:\\Inf.System\\Products\\Computers\\ProductList.txt";
	string mobilesPath = "C:\\Inf.System\\Products\\Mobiles\\ProductList.txt";
	string ipadsPath = "C:\\Inf.System\\Products\\Ipads\\ProductList.txt";

	switch (categoryNumber)
	{
	case 1:
		compucterFile.open(computersPath);
		break;
	case 2:
		ipadFile.open(ipadsPath);
		break;
	case 3:
		mobileFile.open(mobilesPath);
		break;
	case 4:
		compucterFile.open(computersPath);
		ipadFile.open(ipadsPath);
		mobileFile.open(mobilesPath);
		break;
	}

	if (compucterFile.is_open())
	{
		string tmp;

		while (compucterFile.good())
		{
			compucterFile >> tmp;
			nikolaj.push_back(tmp);
		}
		
		compucterFile.close();
	
	}
	
	if (ipadFile.is_open()) // отдает список товаров(АЙПАДЫ)
	{
		string tmp;

		while (ipadFile.good())
		{
			ipadFile >> tmp;
			nikolaj.push_back(tmp);
		}

		ipadFile.close();
		
	}

	if (mobileFile.is_open())
	{
		string tmp;

		while (mobileFile.good())
		{
			mobileFile >> tmp;
			nikolaj.push_back(tmp);
		}

		mobileFile.close();
		
	}
	
	return nikolaj;
}