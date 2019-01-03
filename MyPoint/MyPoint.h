#ifndef MyPoint_h
#define MyPoint_h

class Mypoint
{
public:
	Mypoint();
	~Mypoint();
	Mypoint(int,int);
	void Display();
	void SetX(int);
	int GetX();
	void SetY(int);
	int GetY();
	float Distance(Mypoint);
private:
	int mPosX;
	int mPosY;
};



#endif // !My

