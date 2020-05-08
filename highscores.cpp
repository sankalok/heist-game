//highscores.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "highscores.h"
using namespace std;
//printing the top 10 highscores
void printHighScores(string userName, long long userScore)	//Player's userName and userScore
{
	ifstream fin;
	fin.open("highscores.txt");	//opening highscores.txt
	if(fin.fail())
	{
		cout<<"Error in opening File."<<endl;
	}
	int i=1;	//counter
	string name;	//name at each counter
	long long score;	//score at each counter
	cout<<setfill('*')<<setw(47)<<""<<endl;
	cout<<"******************HIGH SCORES******************"<<endl;
	cout<<setfill('*')<<setw(47)<<""<<endl;
	cout<<"POS"<<setfill(' ')<<setw(24)<<"NAME"<<setfill(' ')<<setw(20)<<"SCORE"<<endl;
	while(i<=10)	//while loop to print the formatted highscores for the top 10
	{
		fin>>name>>score;
    	cout<<setfill('0')<<setw(3)<<i<<setfill(' ')<<setw(24)<<name<<setfill(' ')<<setw(20)<<score<<endl;
		i+=1;
	}
	cout<<setfill('*')<<setw(47)<<""<<endl;
	cout<<"USERNAME: "<<userName<<endl;	//prints the userName and userScore
	cout<<"USER SCORE: "<<userScore<<endl;
	cout<<setfill('*')<<setw(47)<<""<<endl;
	cout<<"*****YOU HAVE REACHED THE END OF THE HEIST*****"<<endl;
	cout<<setfill('*')<<setw(47)<<""<<endl;
	fin.close();
	//end of the game
}
