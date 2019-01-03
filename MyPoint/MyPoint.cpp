#include<iostream>
#include<math.h>
#include "MyPoint.h"

using namespace std;

Mypoint::Mypoint()
{
	this->mPosX = 0;
	this->mPosY = 0;
}
Mypoint::Mypoint(int posX, int posY)
{
	this->mPosX = posX;
	this->mPosY = posY;
}
void Mypoint::Display()
{
	cout << "Possition : X= " << this->mPosX << " , Y = " << this->mPosY<<endl;
}
void Mypoint::SetX(int posX)
{
	this->mPosX = posX;
}
int Mypoint::GetX()
{
	return this->mPosX;
}
void Mypoint::SetY(int posY)
{
	this->mPosY = posY;
}
int Mypoint::GetY()
{
	return this->mPosY;
}
float Mypoint::Distance(Mypoint p )
{
	float result;
	result = sqrt(pow((p.GetX() - this->mPosX), 2) + pow((p.GetY() - this->mPosY), 2));
	return result;
}
Mypoint::~Mypoint()
{

}
