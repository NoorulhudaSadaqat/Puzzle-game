#include<iostream>
#include"puzzlegame.h"
#include<cstdlib>
#include<windows.h>
using namespace std;
int main()
{
	puzzle p1; int moves=1;
	cout << "\n\n\n\n\n\n\n\n\t\t**********************" << endl;
	cout << "\t\t Welcome to Puzzle game\n";
	cout << "\t\t***********************" << endl;
	cout << "\tLoading....";
	Sleep(3000);
	system("cls");
	if(p1.turn())
		cout<<"Turn is SuccessFull"<<endl;
	else
	{
		cout <<" \n\n This number Cannot move choose again " << endl;
	}
	Sleep(2000);
	system("cls");
	while (!(p1.iswon()))
	{
		if (p1.turn())
		{
			cout << "Turn is SuccessFull" << endl;
			moves++;
		}
		else
		{
			cout << "\n\nThis number Cannot move choose again " << endl;
		}
		
		Sleep(1000);
		system("cls");
	}
	p1.show();
	cout << "Congratulations You Solved puzzle in " << moves << " moves" << endl;

}