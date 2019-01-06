#pragma once
#ifndef PAITIENT_H
#define PAITIENT_H

#include <vector>
#include "Virus.h"
using namespace std;
class Paitient
{
public:
	Paitient();
	~Paitient();
	void InitResistance();
	void DoStart();
	void TakeMedicine();
	void Dodie();
	int getState();
	vector<Virus*> getVirusList();

private:
	int mResistance;
	vector<Virus*> mVirusList;
	int mState;
	
};

#endif // !PAITIENT_H

