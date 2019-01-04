#include<iostream>
#include "Virus.h"
#include <fstream>
#include <string>
using namespace std;

Virus::Virus() 
{
	this->mDna = new char;
	Virus::DoBorn();
}
Virus::~Virus()
{
	Virus::DoDie();
}
Virus::Virus(Virus &virus)
{
	
}
void Virus::LoadADNInformation()
{
	ifstream infile("ATXG.bin", ios::out | ios::app | ios::binary);
	if (!infile.is_open())
	{
		cout << "no find file! \n";
	}
	else
	{
		char temp[255];
		int i = -1;
		while (!infile.eof())
		{
			infile.getline(temp, 255);
		}
		this->mDna = temp;
		for (int  j = 1; j < 48 ; j++)
		{
			cout << *(this->mDna + j);
		}
		cout << endl;
	}
	infile.close();
}
void Virus::ReduceResistance(int medicineResistance)
{
	this->mResistance = this->mResistance - medicineResistance;
	if (this->mResistance <= 0)
	{
		Virus::DoDie();
	}
}
