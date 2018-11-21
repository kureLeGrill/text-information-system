#pragma once
#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <ctime> // для считывания времени библиотека
#include "product.h"

using namespace std;

class Order {
	
private:
	string date;
	int totallCost;
	vector<int> allModelsPrice;
	vector<string> allModelsName;
	vector<int> allProductAmount;
	vector<char> allProductType;

public:
	Order();

	~Order();

	Order(string datej, int price, string name, int amount, char type);

	Order(const Order &d); //copy

	Order operator=(const Order &s); 

	void SetDate();
	void calculateAllCost(int productPrice);
	void setPrice(int price);
	void setName(string productName);
	void setAmount(int amount);
	void fillOrder(Product newProductAlldata);
	void updateProductList();
	void SaveOrderToFile(string name, vector<Product> productList);
	void setType(char t);
};