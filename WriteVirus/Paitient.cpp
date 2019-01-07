#include "Paitient.h"
#include "FluVirus.h"
#include "Virus.h"
#include "DengueVirus.h"
#include <iostream>
using namespace std;
enum species
{
	Fluvirus = 1,
	Denguevirus =2 
};
Paitient::Paitient()
{
	this->InitResistance();
	this->DoStart();
}

Paitient::~Paitient()
{
}

void Paitient::InitResistance()
{
	int n = rand() % 8001 + 1000;
	this->mResistance = n;
}

void Paitient::DoStart()
{
	this->mState = 1;
	int viruses = rand() % 11 + 10;
	for (int i = 0; i < viruses; i++)
	{
		int randvirus = rand() % 2 + 1;
		if (randvirus == Fluvirus)
		{
			FluVirus * fluVirus = new FluVirus();
			this->mVirusList.push_back(fluVirus);
		}
		else
		{
			DengueVirus * denVirus = new DengueVirus();
			this->mVirusList.push_back(denVirus);
		}
	}
}

void Paitient::TakeMedicine()
{
	int medicine_resistance = rand() % 30 + 1;
	int viruslistSize = this->mVirusList.size();
	int countVirusAfter = 0;
	cout << "medicine_resistance: "<<medicine_resistance << endl;
	cout << "virus before drink drug : "<<viruslistSize << endl;;
	for (int i = 0; i < viruslistSize; i++)
	{
		if (this->mVirusList[i]->getMResistance() > 0)
		{
			this->mVirusList[i]->ReduceResistance(medicine_resistance);
			if (this->mVirusList[i]->getMResistance() > 0)
			{
				for (auto virusclone : this->mVirusList[i]->DoClone())
				{
					this->mVirusList.push_back(virusclone);
				}
			}
		}
	}
	viruslistSize = this->mVirusList.size();
	int countResistanceVirus= 0;
	for (int i = 0; i < viruslistSize; i++)
	{
		if (this->mVirusList[i]->getMResistance() > 0 )
		{
			countResistanceVirus += this->mVirusList[i]->getMResistance();
			countVirusAfter += 1;
		}
	}
	if (countResistanceVirus > this->mResistance)
	{
		this->Dodie();
	}
	cout << "after clone : " << countVirusAfter << endl;
	if (countVirusAfter == 0)
	{
		cout << "paitient recover! \n";
		cout << "Patients can leave the hospital !" << endl;
	}


}

void Paitient::Dodie()
{
	this->mState = 0;
}

int Paitient::getState()
{
	return this->mState;
}

vector<Virus*> Paitient::getVirusList()
{
	return this->mVirusList;
}
