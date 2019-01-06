#include "Paitient.h"
#include "FluVirus.h"
#include "Virus.h"
#include "DengueVirus.h"
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
	int medicine_resistance = rand() % 60 + 1;
	for (auto virus : this->mVirusList)
	{
		virus->ReduceResistance(medicine_resistance);
	}
	for (auto virus : this->mVirusList)
	{
		if (virus->getMResistance() > 0)
		{
			for (auto virusclone : virus->DoClone())
			{
				this->mVirusList.push_back(virusclone);
			}
		}
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
