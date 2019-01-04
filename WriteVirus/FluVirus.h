#ifndef FLUVIRUS_H
#define FLUVIRUS_H

#include "Virus.h"
#include <vector>

class FluVirus : public Virus
{
public:
	FluVirus();
	~FluVirus();
	FluVirus(const FluVirus *);
	 void DoBorn() override;
	 std::vector<Virus*> DoClone() override;
	 void DoDie() override;
	 void InitREsistance() override;
	 void setMColor(int);
	 int getMColor();
	 void PrintDNA();

private:
	int mColor;
};


#endif // !VIRUS_H#pragma once
