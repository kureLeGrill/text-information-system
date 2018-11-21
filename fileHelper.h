#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

namespace fileHelper //���� �������� � �������� �������
{
	string CharToString(char* str)
	{
		string s;

		for (int i = 0; i < strlen(str); i++)
		{
			s = s + str[i];
		}

		return s;
	}

	char* stringToChar(string one) //������� ����������� ������ � ���
	{
		char* kk = new char[0];
		int dd = 0;
		for each(char c in one)
		{
			kk[dd] = c;
			dd++;
		}

		return kk;
	}

	vector<string> doubleFileReader(string fileName)
	{
		vector<string> fileData;
		string userName;
		string tmp;

		ifstream fileForReading;
		fileForReading.open(fileName);

		while (fileForReading.good())
		{
			fileForReading >> tmp;
			fileData.push_back(tmp);
		}

		return fileData;
	}

	int stringCompare(string first, string second) //��������� �����, ���� ������ ���������� ���������� 1 ���� ��� �� 0
	{
		char* firstTmp = new char[0];
		char* secondTmp = new char[0];
		int answer;

		firstTmp = stringToChar(first);
		secondTmp = stringToChar(second);

		if (first.length()<second.length())
		{
			return 10;
		}

		if (first.length() > second.length())
		{

			return -10;
		}

		for (int i = 0; i<first.length(); i++)
		{

			if (firstTmp[i] == secondTmp[i])
			{
				answer = 1;

			}
			else if (firstTmp[i] != secondTmp[i])
			{
				answer = 0;
				break;
			}

		}



		return answer;
	}
	bool FindSameLogin(vector<string> fileData, string login )
	{
		bool answer;
		int elementCount = fileData.size();
		for(int i = 0;i<elementCount;i++)
		{
			if (stringCompare(fileData[i], login) == 1)
			{
				answer = true;
				break;
			}
			else
			{
				answer = false;
			}
		}
		return answer;
	}
}