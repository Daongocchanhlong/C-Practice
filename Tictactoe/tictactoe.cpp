#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;
char a[3][3] = { '1','2','3','4','5','6','7','8','9' };
char pl1[20], pl2[20];
int mode;

char checkwin(char a[3][3])
{
	char line[3];
	for (int i = 1; i <= 8; i++)
	{
		switch (i)
		{
		case 1:

			line[0] = a[0][0];
			line[1] = a[0][1];
			line[2] = a[0][2];
			break;
		case 2:

			line[0] = a[1][0];
			line[1] = a[1][1];
			line[2] = a[1][2];
			break;
		case 3:

			line[0] = a[2][0];
			line[1] = a[2][1];
			line[2] = a[2][2];
			break;
		case 4:

			line[0] = a[0][0];
			line[1] = a[1][0];
			line[2] = a[2][0];
			break;
		case 5:

			line[0] = a[0][1];
			line[1] = a[1][1];
			line[2] = a[2][1];
			break;
		case 6:

			line[0] = a[0][2];
			line[1] = a[1][2];
			line[2] = a[2][2];
			break;
		case 7:

			line[0] = a[0][0];
			line[1] = a[1][1];
			line[2] = a[2][2];
			break;
		case 8:

			line[0] = a[0][2];
			line[1] = a[1][1];
			line[2] = a[2][0];
			break;

		}

		if (line[0] == 'X'&& line[1] == 'X'&& line[2] == 'X')
		{
			return '1';
		}
		else if (line[0] == 'O'&& line[1] == 'O' && line[2] == 'O')
		{
			return '2';
		}
	}
}
void prmatch(char a[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "|"<<a[i][j] << "|";
		}
		cout <<endl << "----------" <<endl;
	}
}
void modegame(int i)
{
	
}
bool checkron(int i, int j)
{
	if (i == 0 || i > 3 || j == 0 || j > 3 )
	{
		cout << "you can input ron";
		return false;
	}
	else
	{
		return true;
	}
}

 void main()
{
	cout << "welcom to tictactoe game! play with your way!"<<endl;
	cout << "if you find any problem, please contact me abc@gmail.com" << endl;
	cout << "SELECT YOUR MODE (1-PLAY GAME , OTHER- EXIT GAME)" << endl;
	cin >> mode;
	switch (mode)
	{
	case 1:
		cout << "enter player 1 name :" << endl;
		cin >> pl1;
		cout << "enter player 2 name :" << endl;
		cin >> pl2;
		//prmatch(a);
		while (true)
		{
			int i, j;
			int count = 1;
			prmatch(a);
			do
			{
				cout << "your turn " << pl1 << ":";
				cin >> i >> j;
				if (a[i - 1][j - 1] != 'X' && a[i - 1][j - 1] != 'X' && checkron(i, j) == true)
				{
					a[i - 1][j - 1] = 'X'; break;
				}
				else
				{
					cout << "choice ron!rechoice please" << endl;
					
				}
			} while (true);

			if (checkwin(a) == '1')
			{
				cout << pl1 << " win";
				break;
			}
			else if (checkwin(a) == '2')
			{
				cout << pl2 << " win";
				break;
			}
			if (count == 9)
			{
				cout << "draw";
				break;
			}
			prmatch(a);
			do
			{
				cout << "your turn " << pl2 << ":";
				cin >> i >> j;
				if (a[i - 1][j - 1] != 'O' && a[i - 1][j - 1] != 'X' && checkron(i, j) ==  true)
				{
					a[i - 1][j - 1] = 'O'; break;
				}
				else
				{
					cout << "choice ron!rechoice please" << endl;
					
				}
			} while (true);
			

			prmatch(a);
			if (checkwin(a) == '1')
			{
				cout << pl1 << " win";
				break;
			}
			else if (checkwin(a) == '2')
			{
				cout << pl2 << " win";
				break;
			}
			if(count == 9) 
			{
				cout << "draw";
				break;
			}
			count++;
			system("CLS");
		}
		break;
	}

	getchar();
}



