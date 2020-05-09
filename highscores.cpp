//highscores.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "highscores.h"
using namespace std;
//printing the top 10 highscores
void printHighScores()	//Player's userName and userScore
{
	ifstream fin;
	ifstream fin2;
	fin.open("highscores.txt");	//opening highscores.txt
	fin2.open("highscores.txt"); //opening highscores.txt
	string name;	//name at each counter
	long long score;	//score at each counter
	long long count=0;
	while(fin2>>name>>score)
	{
		count+=1;
	}
	int i=1;	//counter
	cout<<setfill('*')<<setw(47)<<""<<endl;
	cout<<"******************HIGH SCORES******************"<<endl;
	cout<<setfill('*')<<setw(47)<<""<<endl;
	cout<<"POS"<<setfill(' ')<<setw(24)<<"NAME"<<setfill(' ')<<setw(20)<<"SCORE"<<endl;
	if(count>=10)
	{
		while(i<=10)	//while loop to print the formatted highscores for the top 10
		{
			fin>>name>>score;
    		cout<<setfill('0')<<setw(3)<<i<<setfill(' ')<<setw(24)<<name<<setfill(' ')<<setw(20)<<score<<endl;
			i+=1;
		}
	}
	else
	{
		while(i<=count)	//while loop to print the formatted highscores for the top 10
		{
			fin>>name>>score;
    		cout<<setfill('0')<<setw(3)<<i<<setfill(' ')<<setw(24)<<name<<setfill(' ')<<setw(20)<<score<<endl;
			i+=1;
		}
		for(i=count+1; i<=10; i++)
		{
			cout<<setfill('0')<<setw(3)<<i<<setfill(' ')<<setw(24)<<"---"<<setfill(' ')<<setw(20)<<0<<endl;
		}
	}
	cout<<setfill('*')<<setw(47)<<""<<endl;
	fin.close();
	//end of the game
}
