#include <iostream>
#include <fstream>
#include "Virus.h"

using namespace std;
int main()
{
	Virus *virus = new Virus();
	virus->LoadADNInformation();
	system("pause");
	return 0;
}
