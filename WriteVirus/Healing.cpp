#include <iostream>
#include <fstream>
#include "Virus.h"
#include "FluVirus.h"
#include "DengueVirus.h"
#include <time.h>
#include "Paitient.h"

using namespace std;

int main()
{
	srand(time(0));

	Paitient * paitient = new Paitient();
	char t = '1';
	while (paitient->getState() == 1 && t == '1')
	{
		printf("Take Medicine (0 = NO, 1 = YES : ");
		cin >> t;
		if (t == '1')
		{
			paitient->TakeMedicine();
		}
	}
	system("pause");
	return 0;
}
