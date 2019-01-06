#ifndef DENVIRUS_H
#define DENVIRUS_H

#include "Virus.h"
#include <vector>
#include <string>
using namespace std;

class DengueVirus : public Virus
{
public:
	DengueVirus();
	~DengueVirus();
	DengueVirus(const DengueVirus *);
	void DoBorn() override;
	std::vector<Virus*> DoClone() override;
	void DoDie() override;
	void InitREsistance() override;
	void setMProtein(string);
	string getMProtein();

private:
	string mProtein;
};


#endif // !VIRUS_H#pragma once
