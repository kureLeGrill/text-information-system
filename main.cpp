#include <iostream>
#include "users.h"
#include "guest.h"
#include "textHelper.h"
#include "clients.h"
#include "product.h"
#include <vector>
#include "order.h"
#include <string>
#include "is.h"

using namespace std;
using namespace Text;

int main()
{
	vector<Product> prodctList; // записываем выбранные продукты, сюда

	string z;
	string ano = "y";
	string ne = "n";
	string retry = "r";
	int h;
	string name;
	User user; //
			   //Test.checkPassword("test","123");
	Guest guest;
	Guest g2;

	string password;
	Is *is;
	is = &user;
	string dd;
	
	bool check = false;

	do
	{	
		allTextHere(31);
		cin >> dd;
		check = is->checkConfigFile(dd);
		
	} while (check == false);

	char input;
	bool checkRetry = false;
	int checkIfFindNotAllowSymbol;
	while (true)
	{
		if (checkRetry == false)
		{
			allTextHere(0); // "Hello dear human"
			allTextHere(1); // 
			allTextHere(2);
			allTextHere(18);
			allTextHere(30);
			cin >> input;
		}
		
		if (input == '1' || checkRetry == true)//login
		{
			checkRetry = false;
			allTextHere(3);

			cin >> name;
			checkIfFindNotAllowSymbol = user.controlSymbols(name);
			if (checkIfFindNotAllowSymbol == 2)
			{
				allTextHere(14);
				allTextHere(15);
	
			}
			else if (checkIfFindNotAllowSymbol == 1)
			{
				allTextHere(14);
				allTextHere(15);
	
			}
			if (checkIfFindNotAllowSymbol == 0)
			{
				allTextHere(4);
				cin >> password;
				checkIfFindNotAllowSymbol = user.controlSymbols(password);
			}

			if (checkIfFindNotAllowSymbol == 2)
			{
				allTextHere(16);
				allTextHere(17);
	
			}
			else if (checkIfFindNotAllowSymbol == 1)
			{
				allTextHere(16);
				allTextHere(17);
	
			}

			if (user.login(name, password) == 1 && checkIfFindNotAllowSymbol == 0) //выводим удачный логин клиент
			{
				allTextHere(5);
				allTextHere(6);
	
				cout << name << "\n";
				Clients client(name);
				while (true)
				{
					allTextHere(20); //"Press 1 to create new order"
					allTextHere(21);
					allTextHere(22);
		
					char chooseCommande;
					cin >> chooseCommande;
					switch (chooseCommande)
					{
					case '1' :
						while (true)
						{
							allTextHere(29);// "In which category, you want create a order?"		
							allTextHere(23); // "Press 1 to choose computer category."
							allTextHere(24);
							allTextHere(25);
							allTextHere(26);
							allTextHere(32);//"press e for break"
							string categ;
							cin >> categ;
							if (categ == "q")
							{
								break;
							}
							prodctList.push_back(client.operator+(categ));
							//prodctList.push_back(client.chooseOrder(categ)); // записыаем с помщ "пущЅэк" в конец массива
							cout << "Do you want to buy anything else?"<<endl;
							allTextHere(10);
							allTextHere(11);
							char choose;
							cin >> choose;

							if (choose == 'y')
							{

							}
							else if(choose == 'n')
							{
								Order newOrder;
								newOrder.SaveOrderToFile(client.getName(), prodctList);
								break;
							}
							
						}
						break;
					case '2':
						break;
					case '3':
						break;
					}
				}

			}
			else if (user.login(name, password) == 2 && checkIfFindNotAllowSymbol == 0) // stuff
			{
				allTextHere(5);
				allTextHere(7);
	
				cout << name << "\n";
			}
			else//если не смог залогинетьс€
			{
				allTextHere(8);
				allTextHere(9);
				allTextHere(10);
				allTextHere(11);
				allTextHere(20);
	
				cin >> z;
				if (z == ano)
				{
					allTextHere(12);
		
					string tmp;
					cin >> tmp;
					string &newLoginName = tmp; // Reference jako parametr funkce a nvratov hodnota
					
					bool check;
					check = false;
					check = user.checkNewLogin(newLoginName);

					if (check == false)
					{
						guest.registration_new_user(newLoginName); 
						cout << "creation is successful" << endl;
						cout << "put the new password down" << endl;
						string password;
						cin >> password;
						user.createNewPasswordForNewUser(newLoginName, password);

					}


					else if (check == true)
					{
						cout << "Login is taken" << endl;
					}
				}
				else if(z == ne)
				{
					cout << "zzz!\n";

				}
				else if (z == retry)
				{
					checkRetry = true;
				}
			}
		}
		 else if(input == '2') // information point
		{
			system("cls");
			allTextHere(27);
			allTextHere(28);
			allTextHere(30);
			cin >> input;
			if (input == '3')
			{
				break;
			}
			else
			{
				cout << "try again";
			}
		}
		else if (input == '3')
		{
			break;
		}
		cin.get();
	}
}