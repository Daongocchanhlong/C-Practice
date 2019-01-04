#include "Virus.h"
#ifndef FLUVIRUS_H
#define FLUVIRUS_H
class FluVirus : public Virus
{
public:
	FluVirus();
	~FluVirus();
	 void DoBorn() override;
	 Virus* DoClone()override;
	 void DoDie()override;
	 void InitREsistance() override;

private:
	int mColor;
};

#endif // !VIRUS_H#pragma once
