#include<iostream>
#include "Virus.h"
#include <fstream>
#include <string>
using namespace std;

Virus::Virus() 
{
	this->mDna = new char[100];

}

Virus::~Virus()
{
	delete this->mDna;
}

Virus::Virus(const Virus* virus)
{
	this->mDna = new char[100];

	for (int i = 1; i < 100; i++)
	{
		(this->mDna[i]) = (virus->mDna[i]);
	}
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
		
		while (!infile.eof())
		{
			infile.getline(this->mDna, 100);
		}
		
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
