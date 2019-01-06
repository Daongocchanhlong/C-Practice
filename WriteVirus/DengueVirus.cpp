#include "DengueVirus.h"
#include <vector>
#include<string>
#include<iostream>

using namespace std;
DengueVirus::DengueVirus()
{
	this->DoBorn();
	this->InitREsistance();
}

DengueVirus::~DengueVirus()
{
}

DengueVirus::DengueVirus(const DengueVirus * denVirus)
{
	*this = *denVirus;
}

void DengueVirus::DoBorn()
{
	this->LoadADNInformation();
	int n = rand() % 3 + 1;
	if (n == 1)
	{
		this->mProtein = "NS3";
	}
	else if (n == 2 )
	{
		this->mProtein = "NS5";
	}
	else
	{
		this->mProtein = "E";
	}
}

std::vector<Virus*> DengueVirus::DoClone()
{
	vector<Virus*> listvirus;
	DengueVirus *newDenvirus1 = new DengueVirus(this);
	listvirus.push_back(newDenvirus1);
	DengueVirus *newDenvirus2 = new DengueVirus(this);
	listvirus.push_back(newDenvirus2);
	return	listvirus;
}

void DengueVirus::DoDie()
{
	this->mProtein = "";
}

void DengueVirus::InitREsistance()
{
	if (this->mProtein == "NS3")
	{
		int n = rand() % 10 + 1;
		this->setMResistance(n);
	}
	if (this->mProtein == "NS5")
	{
		int n = rand() % 10 + 11;
		this->setMResistance(n);
	}
	else
	{
		int n = rand() % 10 + 21;
		this->setMResistance(n);
	}
}

void DengueVirus::setMProtein(string mProtein)
{
	this->mProtein = mProtein;
}

string DengueVirus::getMProtein()
{
	return this->mProtein;
}


