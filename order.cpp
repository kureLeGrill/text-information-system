#include <vector>
#include <string>
#include "order.h"
#include <ctime>
#include <fstream>
#include "product.h"

Order::Order() // обычный конструктор
{
	totallCost = 0;
	date = "";
}

Order::Order(string datej, int price, string name, int amount, char type) //параметрический конструктор
{
	totallCost = price;
	setPrice(price);
	setName(name);
	setType(type);
	setAmount(amount);
	SetDate();
}

Order::~Order() // деструктор
{
	totallCost = 0;
	date = "";
	allProductAmount.clear();
	allModelsName.clear();
	allModelsPrice.clear();
}

Order::Order(const Order &d) //копи конструктор
{
	date = d.date;
	totallCost = d.totallCost;

	for (int c = 0; c < allModelsPrice.size(); c++)
	{

		allModelsPrice[c] = d.allModelsPrice[c];
		allModelsName[c] = d.allModelsName[c];
		allProductAmount[c] = d.allProductAmount[c];
		allProductType[c] = d.allProductType[c];
	}
}

Order Order::operator=(const Order &s)
{
	totallCost = s.totallCost;
	date = s.date;

	for (int i = 0; i<allModelsPrice.size(); i++)
	{
		allModelsPrice[i] = s.allModelsPrice[i];
		allModelsName[i] = s.allModelsName[i];
		allProductAmount[i] = s.allProductAmount[i];
		allProductType[i] = s.allProductType[i];
	}

	return *this;
}


void Order::calculateAllCost(int productPrice)
{
	totallCost += productPrice;
}

void Order::setType(char t)
{
	allProductType.push_back(t);
}



void Order::SetDate()
{
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	date = asctime(timeinfo);
}

void Order::setPrice(int price)
{
	allModelsPrice.push_back(price);

}

void Order::setName(string name)
{
	allModelsName.push_back(name);
}

void Order::setAmount(int amount)
{
	allProductAmount.push_back(amount);
}

template <typename T>
string NumberToString(T Number)
{
	stringstream ss;
	ss << Number;
	return ss.str();
}

void Order::SaveOrderToFile(string name, vector<Product> productList)
{
	string pathToDirectory = "C:\\Inf.System\\Order\\";
	ofstream fileForNewOrder;
	fstream fileNumber;
	string newNameForNewOrderInNewTxt;
	string number;

	fileNumber.open("C:\\Inf.System\\Order\\Number.txt");
	fileNumber >> number;
	fileNumber.close();
	fileNumber.open("C:\\Inf.System\\Order\\Number.txt");
	string cc;
	cc = to_string(stoi(number) + 1);
	fileNumber << cc;
	fileNumber.close();

	newNameForNewOrderInNewTxt = name + "_" + number + "_" + date + ".txt";

	fileForNewOrder.open(pathToDirectory + newNameForNewOrderInNewTxt);//вот тут открываем файл
	if (fileForNewOrder.is_open())
	{
		for each(Product c in productList)
		{
			fillOrder(c);
		}
		//а теперь записываем в файл он уже открыт выще
		fileForNewOrder << totallCost << " || ";
		fileForNewOrder << date << endl;

		for (int i = 0; i < allModelsPrice.size(); i++) //!!!
		{
			fileForNewOrder << allModelsName[i] << " || " << allModelsPrice[i] << " || " << allProductAmount[i] << " || " << allProductType[i] << endl;

		}

		fileForNewOrder.close();
		updateProductList();
	}
}

void Order::fillOrder(Product newProductAllData)
{
	SetDate();
	setPrice(newProductAllData.GetPrice());

	string nameFromProduct;
	nameFromProduct = newProductAllData.GetName();
	setName(nameFromProduct);

	int priceFromProdcut;
	priceFromProdcut = newProductAllData.GetPrice();
	calculateAllCost(priceFromProdcut);
	
	int productAmount;
	productAmount = newProductAllData.GetAmount();
	setAmount(productAmount);

	char type;
	type = newProductAllData.GetType();
	setType(type);
}


void Order::updateProductList()
{
	string computersPath = "C:\\Inf.System\\Products\\Computers\\ProductList.txt";
	string mobilesPath = "C:\\Inf.System\\Products\\Mobiles\\ProductList.txt";
	string ipadsPath = "C:\\Inf.System\\Products\\Ipads\\ProductList.txt";

	bool categComp = false;
	bool categIpad = false;
	bool categMobile = false;

	for (int i = 0; i < allProductType.size(); i++)
	{
		if (allProductType[i] == 'm')
		{
			categMobile = true;
		}
		else if (allProductType[i] == 'p')
		{
			categComp = true;
		}
		else if (allProductType[i] == 'i')
		{
			categIpad = true;
		}
	}

	if (categComp == true) 
	{
		ifstream FileProductList;
		FileProductList.open(computersPath);
		vector<string> product;

		if (FileProductList.is_open()) // заполняем vector<string> products
		{
			while (FileProductList.good()) // если есть строчки в этом файле
			{
				string shpric;

				FileProductList >> shpric;
				product.push_back(shpric);
			}
		}
		FileProductList.close();

		for (int i = 0; i < allModelsName.size(); i++) // меняем клон
		{
			if (allProductType[i] == 'p')
			{
				for (int j = 0; j < product.size(); j++ )
				{
					int checkSemiCol = 0;
					string productName;
					string productAmout;
					string productPrice;
					for each(char c in product[j])
					{
						if (c != ';' && checkSemiCol == 0)
						{
							productName = productName + c;
						}
						if (c != ';' && checkSemiCol == 1)//считываем цену из файла с Категориями
						{
							productPrice = productPrice + c;
						}
						if (c != ';' && checkSemiCol == 2)//считываем цену из файла с Категориями
						{
							productAmout = productAmout + c;
						}
						if (c == ';')
						{
							checkSemiCol++;
						}
					}
					int productAmountInteger = stoi(productAmout);
					if (productName == allModelsName[i])
					{
						productAmountInteger = productAmountInteger - allProductAmount[i];
						string tmp;
						string cc;
						cc = to_string(productAmountInteger);
						tmp = allModelsName[i] + ";" + productPrice + ";" + cc;
						product[j] = tmp;
						break;
					}
				}//konec cykla po zamene jacejky
			}
		}//konec cykla po zamene vsech jaceek

		ofstream FileProductListRewrite;
		FileProductListRewrite.open(computersPath);

		if (FileProductListRewrite.is_open())
		{
			for each (string var in product)
			{
				FileProductListRewrite << var << endl;
			}
		}
		FileProductListRewrite.close();
	}
	if (categIpad == true)
	{
		ifstream FileProductList;
		FileProductList.open(ipadsPath);
		vector<string> product;

		if (FileProductList.is_open()) // заполняем vector<string> products
		{
			while (FileProductList.good()) // если есть строчки в этом файле
			{
				string shpric;

				FileProductList >> shpric;
				product.push_back(shpric);
			}
		}
		FileProductList.close();

		for (int i = 0; i < allModelsName.size(); i++) // меняем клон
		{
			if (allProductType[i] == 'i')
			{
				for (int j = 0; j < product.size(); j++)
				{
					int checkSemiCol = 0;
					string productName;
					string productAmout;
					string productPrice;
					for each(char c in product[j])
					{
						if (c != ';' && checkSemiCol == 0)
						{
							productName = productName + c;
						}
						if (c != ';' && checkSemiCol == 1)//считываем цену из файла с Категориями
						{
							productPrice = productPrice + c;
						}
						if (c != ';' && checkSemiCol == 2)//считываем цену из файла с Категориями
						{
							productAmout = productAmout + c;
						}
						if (c == ';')
						{
							checkSemiCol++;
						}
					}
					int productAmountInteger = stoi(productAmout);
					if (productName == allModelsName[i])
					{
						productAmountInteger = productAmountInteger - allProductAmount[i];
						string tmp;
						string cc;
						cc = to_string(productAmountInteger);
						tmp = allModelsName[i] + ";" + productPrice + ";" + cc;
						product[j] = tmp;
						break;
					}
				}//konec cykla po zamene jacejky
			}
		}//konec cykla po zamene vsech jaceek

		ofstream FileProductListRewrite;
		FileProductListRewrite.open(ipadsPath);

		if (FileProductListRewrite.is_open())
		{
			for each (string var in product)
			{
				FileProductListRewrite << var << endl;
			}
		}
		FileProductListRewrite.close();
	}
	if (categMobile == true)
	{
		ifstream FileProductList;
		FileProductList.open(mobilesPath);
		vector<string> product;

		if (FileProductList.is_open()) // заполняем vector<string> products
		{
			while (FileProductList.good()) // если есть строчки в этом файле
			{
				string shpric;

				FileProductList >> shpric;
				product.push_back(shpric);
			}
		}
		FileProductList.close();

		for (int i = 0; i < allModelsName.size(); i++) // меняем клон
		{
			if (allProductType[i] == 'm')
			{
				for (int j = 0; j < product.size(); j++)
				{
					int checkSemiCol = 0;
					string productName;
					string productAmout;
					string productPrice;
					for each(char c in product[j])
					{
						if (c != ';' && checkSemiCol == 0)
						{
							productName = productName + c;
						}
						if (c != ';' && checkSemiCol == 1)//считываем цену из файла с Категориями
						{
							productPrice = productPrice + c;
						}
						if (c != ';' && checkSemiCol == 2)//считываем цену из файла с Категориями
						{
							productAmout = productAmout + c;
						}
						if (c == ';')
						{
							checkSemiCol++;
						}
					}
					int productAmountInteger = stoi(productAmout);
					if (productName == allModelsName[i])
					{
						productAmountInteger = productAmountInteger - allProductAmount[i];
						string tmp;
						string cc;
						cc = to_string(productAmountInteger);
						
						tmp = allModelsName[i] + ";" + productPrice + ";" + cc;
						product[j] = tmp;
						break;
					}
				}//konec cykla po zamene jacejky
			}
		}//konec cykla po zamene vsech jaceek

		ofstream FileProductListRewrite;
		FileProductListRewrite.open(mobilesPath);

		if (FileProductListRewrite.is_open())
		{
			for each (string var in product)
			{
				FileProductListRewrite << var << endl;
			}
		}
		FileProductListRewrite.close();
	}
}



