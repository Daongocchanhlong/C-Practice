#ifndef VIRUS_H
#define VIRUS_H
#include <vector>

class Virus
{
public:
	Virus();
	~Virus();
	Virus(const Virus *);
	void LoadADNInformation();
	void ReduceResistance(int);
	virtual void DoBorn() = 0;
	virtual std::vector<Virus*> DoClone() = 0;
	virtual void DoDie()=0;
	virtual void InitREsistance() = 0;
	void setMDna(char*);
	char* getMDna();
	void setMResistance(int);
	int getMResistance();



private:
	char *mDna;
	int mResistance;
};
#endif // !VIRUS_H

