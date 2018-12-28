#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;
char square[3][3] = { '1','2','3','4','5','6','7','8','9' };
char player1[20], player2[20];
int mode;

int checkwin(char tempsquare[3][3],int tempcount)
{
	//check row
	for (int i = 0; i < 3; i++)
	{
		if (tempsquare[i][0] == tempsquare[i][1] && tempsquare[i][1] == tempsquare[i][2])
			if (tempsquare[0][0] == 'X')
				return 1;
			else
				return 2;
	}
	//check column
	for (int i = 0; i < 3; i++)
	{
		if (tempsquare[0][i] == tempsquare[1][i] && tempsquare[1][i] == tempsquare[2][i])
			if (tempsquare[0][0] == 'X')
				return 1;
			else
				return 2;
	}
	//chech diagonal line
	if (tempsquare[0][0] == tempsquare[1][1] && tempsquare[2][2] == tempsquare[1][1] || tempsquare[0][2] == tempsquare[1][1] && tempsquare[2][0] == tempsquare[1][1])
		if (tempsquare[0][0] == 'X')
			return 1;
		else
			return 2;
	if (tempcount == 9)
		return 0;
}

void printboard(char square[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "|"<<square[i][j] << "|";
		}
		cout <<endl << "----------" <<endl;
	}
}

bool checkWronginput(int i, int j)
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
		cin >> player1;
		cout << "enter player 2 name :" << endl;
		cin >> player2;
		//printboard(square);
		while (true)
		{
			int i, j;
			int count = 1;
			printboard(square);
			do
			{
				cout << "your turn " << player1 << ":";
				cin >> i >> j;
				if (square[i - 1][j - 1] != 'X' && square[i - 1][j - 1] != 'X' && checkWronginput(i, j) == true)
				{
					square[i - 1][j - 1] = 'X'; 
					break;
				}
				else
				{
					cout << "choice ron!rechoice please" << endl;
					
				}
			} while (true);

			if (checkwin(square, count) == 1)
			{
				cout << "plyer " << player1 << " Win " << endl;
				break;
			}
			else if (checkwin(square, count) == 2)
			{
				cout << "plyer " << player2 << " Win " << endl;
				break;
			}
			else if (checkwin(square, count) == 0)
			{
				cout << "draw " << endl;
				break;
			}
			
			printboard(square);
			do
			{
				cout << "your turn " << player2 << ":";
				cin >> i >> j;
				if (square[i - 1][j - 1] != 'O' && square[i - 1][j - 1] != 'X' && checkWronginput(i, j) ==  true)
				{
					square[i - 1][j - 1] = 'O'; break;
				}
				else
				{
					cout << "choice wrong!rechoice please" << endl;
					
				}
			} while (true);
			

			printboard(square);

			if (checkwin(square, count) == 1)
			{
				cout << "plyer " << player1 << " Win "<<endl;
				break;
			}
			else if (checkwin(square, count) == 2)
			{
				cout << "plyer " << player2 << " Win " << endl;
				break;
			}
			else if (checkwin(square, count) == 0)
			{
				cout << "draw " << endl;
				break;
			}
			
			count++;
			system("CLS");
		}
		break;
	}
	system("pause");
}



