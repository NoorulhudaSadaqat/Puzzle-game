#include<iostream>
#include "puzzlegame.h"
using namespace std;

    puzzle::puzzle()
    {
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				arr[i][j]=0;
			}
		}
        int filling[9], count = 0; //filling is array which will store all the numbers already stored in puzzle
        for (int i = 0; i < 3; i++)// will handle the rows
        {
			
            for (int j = 0; j < 3; )// will handle the columns
            {
			
				bool exist=false;
                //c:
                int num = rand() % 8 + 1;// generating a random number between 0-9
				int row=rand()%3;
				int col=rand()%3;
				
                for (int k = 0; k < 9; k++)// to check if generated number is already stored in puzzle
                {
                    if (num == filling[k] || arr[row][col] != 0)
					{
						exist=true;
						break;
                        //goto c;// if the number is already used go back and again generate number
                    }
                }
				
				if(!exist){
                    arr[row][col] = num;
                    filling[count] = num; count++;
					j++;
			
				}
				if(i==2 && j==2)
					break;
            }
        }
    }
    void puzzle::show()// to display th puzzle board
    {
        for (int i = 0; i < 3; i++)
        {
            cout << "\t_____________" << endl;
            cout << "\t|";
            for (int j = 0; j < 3; j++)
            {
                if (arr[i][j]==0)
                {
                    cout << "   |";
                }
                else
					cout << " "<<arr[i][j] << " |";
            }
            cout << endl;
        }
        cout << "\t_____________" << endl;
    }
    void puzzle::move(int num)
    {
        int row=0, col=0;
        for (int i = 0; i < 3; i++)//to find the row of number to be moved
        {
            for (int j = 0; j < 3; j++)//to find the column of numberto be moved
            {
                if (arr[i][j] == num)
                {
                    row = i; col = j;
                     break;//once we get the row and column break the loop because we are done
                }
            }
        }
        //next working is to find the free space near the number to be moved
        if (row-1>=0 && arr[row - 1][col] == 0)//to check if the number can be moved upward
        {
            arr[row - 1][col] = num;
            arr[row][col] = 0;
        }
        else if (row+1< 3 && arr[row +1][col] == 0)//to check if the number can be moved downward
        {
            arr[row + 1][col] = num;
            arr[row][col] = 0;
        }
        else if (col-1 >= 0 && arr[row][col-1] == 0)//to check if the number can be moved left
        {
            arr[row][col-1] = num;
            arr[row][col] = 0;
        }
        else if (col + 1 < 3 && arr[row][col+1] == 0)//to check if the number can be moved right
        {
            arr[row][col+1] = num;
            arr[row][col] = 0;
        }
        else
        {
            //if there is no space near the number print the mesage
            cout << num << "  Cannot move choose again " << endl;
        }
    }
    bool puzzle::iswon()
    {
        //player is won when the numbers 1-8 ar placed in ascending order in the puzzle board
        int num = 1; bool flag = true;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (arr[i][j] != num)//if atleast one number is not in its place return false
                {
                    flag = false;
                }
            }
        }
        return flag;
    }
    void puzzle::turn()
    {
        int input;
        this->show();
        cout << "\n Enter the number you want to move :";
        cin >> input;
        this->move(input);
    }

