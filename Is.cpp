#include <iostream>
#include "is.h"
#include <fstream>
#include <string>

using namespace std;

Is::Is()
{
	nameIs = "";
}

Is::Is(const Is &n) //copy
{
	nameIs = n.nameIs;
}

Is::Is(string namej)
{
	nameIs = namej;
}

Is::~Is()
{
	nameIs = "";
}

Is Is::operator=(const Is &p)
{
	nameIs = p.nameIs;
	return *this;
}


int stringLenght(string str)
{
	int i = 0;

	for each (char d in str)
	{
		i++;
	}

	return i;
}

int Is::createNewId(string IdType)
{
	fstream IdFile;
	string idUser = "IdUser";
	string id;
	IdFile.open("C:\\Inf.System\\Id.txt");
	bool check = false;
	int newId;

	while (IdFile.good())
	{  //good ��������� ������ �� ���������� ������

		string idTypeFromIdFile;
		IdFile >> idTypeFromIdFile; //���������� ������ � �����, � ������

		for (int k = 0; k < stringLenght(idTypeFromIdFile); k++) //������ �������� ������ �� �����
		{

			if (IdType[k] == idTypeFromIdFile[k]) //���������� id type ����������� ���� � �������� � ����� "� ��������� ����������"
			{

				if (idTypeFromIdFile[k + 1] == ';')
				{
					int z = 0;
					for (int aa = k + 2; aa < stringLenght(idTypeFromIdFile); aa++)
					{
						idTypeFromIdFile[aa];
						//strcat(id, idTypeFromIdFile[aa]);
						id[z] = idTypeFromIdFile[aa];
						z++;

					}

					newId = stoi(id);
					newId++;

					
					IdFile.close();

					return newId;
					//IdFile << IdType << ";"
					//break;
				}


			}
		}
		return 0;

	}
}

void Is::rewriteId(int newId, string idType)
{
	fstream fileForId;

}

int Is::controlPassword(string password)
{
	return 0;//temporary
}

bool Is::checkConfigFile(string pathToFileConfig) // ������ ������
{
	fstream configFile;
	string error = "error, is not found";
	cout << "IS testing" << endl;
	try// ������ numer uno
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
