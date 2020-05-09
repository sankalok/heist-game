//mergenameandscore.cpp
#include <iostream>
#include <fstream>
#include <string>
#include "mergenameandscore.h"
using namespace std;
//merging the userName.txt and userScore.txt files
void mergeNameAndScore()
{
	ofstream fout;
	ifstream fin;
	ifstream fin2;
	ifstream fin3;
	fout.open("highscores.txt", ios::app);
	fin.open("userName.txt");
	fin2.open("userName.txt");
	fin3.open("userScore.txt");
	if(fin.fail())
	{
		cout<<"Error in opening File."<<endl;
	}
	if(fin2.fail())
	{
		cout<<"Error in opening File."<<endl;
	}
	if(fin3.fail())
	{
		cout<<"Error in opening File."<<endl;
	}
	long long count=0;
	string name;
	long long score=0;
	while(fin>>name)	//finds the number of names/scores already present in the files
	{
		count+=1;
	}
	for(long long i=0; i<count; i++)	//runs a for loop from i=0 till less than count
	{
		fin2>>name;	//reads the name from userName.txt
		fin3>>score; //reads the score from userScore.txt
		fout<<name<<" "<<score<<endl; //writes the combines name and score into highscores.txt
	}
	fin.close();
	fin2.close();
	fin3.close();
	fout.close();
	//end of the function after closing all the fstreams
}
