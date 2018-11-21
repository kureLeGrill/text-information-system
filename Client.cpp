#include "clients.h"
#include <fstream>
#include <list>
#include <iostream>
#include <string>
#include "product.h"

using namespace std;

Clients::Clients()
{
	name = "";
}

Clients::Clients(string namej)
{
	name = namej;
}

Clients::Clients(string newName, string password)
{
	name = newName;
	password = password;
}

Clients::~Clients()
{
	name = "";
	password = "";
}

Clients::Clients(const Clients &n)
{
	name = n.name;
}

Clients Clients::operator=(const Clients &j)
{
	name = j.name;
	return *this;
}


Product Clients::operator+(string category) //создает new order
{
	char categAll[3] = { 'm','p','i' };

	vector<string> products;
	if (stoi(category) < 4)
	{
		products = getAllProductsFromCategory(stoi(category)); //функйия которая запишет все продукты из продукт листа
		for (int i = 0; i < products.size(); i++)
		{
			cout << to_string(i) << ") " << products[i] << endl;
		}

		cout << "Choose you product?" << endl;
		string productCNumber;
		int pNumber = 0;
		cin >> productCNumber;
		pNumber = stoi(productCNumber) - 1;
		string productName;
		string productCost;
		int checkSemiCol = 0;
		bool error = false;
		try
		{
			string g = "error";
			if (pNumber > 4)throw g;
			for each(char c in products[pNumber])
			{
				if (c != ';' && checkSemiCol == 0)
				{
					productName = productName + c;
				}
				if (c != ';' && checkSemiCol == 1)//считываем цену из файла с Категориями
				{
					productCost = productCost + c;
				}
				if (c == ';')
				{
					checkSemiCol++;
				}
				if (checkSemiCol == 2)
				{
					break;
				}
			}
		}
		catch (string e)
		{
			error = true;
			cout << e << endl;
		}

		if (error == false)
		{
			Product product;
			cout << "Enter Amount" << endl;
			string amount;
			cin >> amount;
			product.SetAmount(stoi(amount));
			product.SetName(productName);
			product.SetPrice(stoi(productCost));

			bool error2 = false;
			do
			{
				try
				{
					string g = "error";
					if (stoi(category) > 4) throw g;
					product.SetType(categAll[stoi(category)]);
					error2 = false;
				}
				catch (string e)
				{
					cout << e << endl;
					error2 = true;
				}
			} while (error2 == true);

			return product;
		}
	}
}

string Clients::getName()
{
	return name;
}

void Clients::setName(string n)
{
	name = n;
}