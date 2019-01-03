#include<iostream>
#include "MyPoint.h"
using namespace std;
int main()
{
	Mypoint *point1 = new Mypoint(0,0);
	Mypoint *point2 = new Mypoint(6,8);

	cout << "distance 2 point: " << point2->Distance(*point1)<<endl;
	system("pause");
	return 0;
}