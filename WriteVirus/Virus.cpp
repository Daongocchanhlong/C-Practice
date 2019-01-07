#include<iostream>
#include "Virus.h"
#include <fstream>
#include <string>
using namespace std;

Virus::Virus() 
{
	this->mDna = new char;

}
Virus::~Virus()
{
	delete this->mDna;
}
Virus::Virus(const Virus* virus)
{
	this->mDna = virus->mDna;
	this->mResistance = virus->mResistance;
}
void Virus::LoadADNInformation()
{
	ifstream infile("ATXG.bin");
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
		this->setMDna(temp);
		
	}
	infile.close();
}
void Virus::ReduceResistance(int medicineResistance)
{
	this->mResistance = this->mResistance - medicineResistance;
	if (this->mResistance <= 0)
	{
		this->DoDie();
	}
}

void Virus::setMDna(char * mDNA)
{
	this->mDna = mDNA;
}

char * Virus::getMDna()
{
	return this->mDna;
}

void Virus::setMResistance(int resistance)
{
	this->mResistance = resistance;
}

int Virus::getMResistance()
{
	return this->mResistance;
}
