#include<iostream>
#include"FluVirus.h"
#include "Virus.h"

using namespace std;
enum color
{
	RED =1 ,
	BLUE =2
};
FluVirus::FluVirus()
{
	this->DoBorn();
	this->InitREsistance();
}
FluVirus::~FluVirus()
{
	this->mColor = 0;
}
FluVirus::FluVirus(const FluVirus *fluVirus)
{
	*this = *fluVirus;
}
void FluVirus::DoBorn()
{
	fflush(stdin);
	this->LoadADNInformation();
	int n = rand() % 2 + 1;
	if (n == 1 )
	{
		this->mColor = RED;
	}
	else
	{
		this->mColor = BLUE;
	}

}
vector<Virus*> FluVirus::DoClone()
{
	vector<Virus*> listvirus;
	FluVirus *newfluvirus = new FluVirus(this);
	listvirus.push_back(newfluvirus);
	return	listvirus;

}
void FluVirus::DoDie()
{
	this->~FluVirus();

}
void FluVirus::InitREsistance()
{
	if (this->mColor == 1 )
	{
		int n = rand() % 10 +10 ;
		this->setMResistance(n);
	}
	else
	{
		int n = rand() % 10 + 15;
		this->setMResistance(n);
	}

}

void FluVirus::setMColor(int mColor)
{
	this->mColor = mColor;

}

int FluVirus::getMColor()
{
	return this->mColor;
}

void FluVirus::PrintDNA()
{
	
	for (int j = 1; j < 48; j++)
	{
		cout << *(this->getMDna()+j);
	}
}
