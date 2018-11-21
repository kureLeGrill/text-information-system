#include "guest.h"
#include <fstream>

using namespace std;

Guest::Guest() 
{
	name = "";
}

Guest::Guest(string jname)
{
	name = jname;
}

Guest::~Guest()
{
	name = "";
}

Guest::Guest(const Guest &h)
{
	name = h.name;
}

Guest Guest::operator=(const Guest &j)
{
	name = j.name;
	return *this;
}

void Guest::registration_new_user(string &newLoginName) //Reference jako parametr funkce a nvratov hodnota
{

	fstream file;
	int newIdForUser = createNewId("iduser");
	
	file.open("C:\\Inf.System\\User\\UserListClient.txt", ios::app);
	file << newLoginName << endl;
	
	file.close();
}
