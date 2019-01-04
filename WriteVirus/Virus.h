#ifndef VIRUS_H
#define VIRUS_H
class Virus
{
public:
	Virus();
	~Virus();
	Virus(Virus &);
	void LoadADNInformation();
	void ReduceResistance(int);
	virtual void Virus::DoBorn() = 0;
	virtual Virus* DoClone() =0;
	virtual void DoDie()=0;
	virtual void InitREsistance() = 0;
private:
	char *mDna;
	int mResistance;
};
#endif // !VIRUS_H

