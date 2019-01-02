#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct student
{
	int id;
	string name;
	float score;
};
vector<student> liststudent;
int checkid(int id) 
{
	for (auto i = liststudent.begin(); i != liststudent.end(); ++i)
	{
		student student = *i;
		if (student.id == id && id < 0)
		{
			return 1;
		}
	}
	return 0;
}
int checkscore(int score)
{
	if (score > 10 || score < 0)
		return 1;
	else return 0;
}

int main()
{
	int choose;
	do
	{
		cout << "-----------------MENU-----------------" << endl;
		cout << "	1. Input " << endl;
		cout << "	2. Display " << endl;
		cout << "	3. Save to file" << endl;
		cout << "	4. Load from file" << endl;
		cout << "	0. exit" << endl;

		cout << "Chosse : ";
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			student student;
			int id;
			float score;
			cout << "please enter student's id : ";
			cin >> id;
			if (checkid(id) == 0)
			{
				cout << "This ID is wrong, Please try input";
				break;
			}
			else
			{
				student.id = id;
			}

			cin.get();
			cout << "please enter student's name : "; 
			getline(cin, student.name);
			cout << "please enter student's score : ";
			cin >> score;
			if (checkscore(score) == 1)
			{
				cout << "this Score wrong, please try input";
				break;
			}
			else student.score = score;
			liststudent.push_back(student);
			break;
		}
		case 2:
		{	
			cout << "ID\tFULL NAME\t\tSCORE" << endl;
			for (auto i = liststudent.begin(); i != liststudent.end(); ++i)
			{
				student student = *i;
				cout << student.id << "\t" << student.name << "\t\t" << student.score << endl;
			}
			break;
		}
		case 3:
		{
			ofstream outfile;
			outfile.open("Liststudent.txt");
			for (auto i = liststudent.begin(); i != liststudent.end(); ++i)
			{
				student student = *i;
				outfile << student.id << endl;
				outfile << student.name << endl;
				outfile << student.score << endl;
			}
			cout << "write file complete!\n";
			outfile.close();
			break;
		}
		case 4:
		{
			string line, name;
			int id;
			float score;
			ifstream infile;
			infile.open("Liststudent.txt");
			while (!infile.eof())
			{
				student  student;
				getline(infile, line);
				if (line == "") break;
				id = stoi(line);
				getline(infile, line);
				name = line;
				getline(infile, line);
				score = stof(line);
				student.id = id;
				student.name = name;
				student.score = score;
				liststudent.push_back(student);
			}
			cout << "load file complete\n";

			infile.close();
			break;
		}
		}
		system("pause");
		system("cls");
	} while (choose != 0);
	system("pause");
	return 0;

}
