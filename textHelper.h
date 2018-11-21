#pragma once
#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <fstream>


using namespace std;

namespace Text {

	template<typename T> // ���� template������� ���������� ��� �������� ������������ ������ ������ ���� 
	T toScreen(T text) 
	{
		cout << text << endl;
		return text;
	}

	void TextOnScreen(vector<string> str, int numberOfVector)
	{
		if (numberOfVector < 0)
		{
			toScreen(345);
			toScreen("Call the programer!");
			return;
		}

		if (numberOfVector >= str.size())
		{
			cout << "Call the programer!" << endl;
			return;
		}

		if (numberOfVector >=0 && numberOfVector < str.size())
		{
			cout << str[numberOfVector] << endl;
		}
	}

	void allTextHere(int numberOfVector) //!!! opravit +++ ���� ����� ������� � ���� ����
	{
		vector<string> text;
		
		fstream fileText;
		string pathToTextFile = "C:\\Inf.System\\Text\\file_text.txt";
		fileText.open(pathToTextFile);

		if (fileText.is_open())
		{
			while (fileText.good())
			{
				string tmp;
				getline(fileText, tmp);
				text.push_back(tmp);
			}
		}

		fileText.close();

		TextOnScreen(text, numberOfVector);
	}
}