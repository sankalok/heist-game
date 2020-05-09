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
	fout.open("highscores.txt");
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
	//dynamic arrays for sorting names and scores in descending order
	string *nameArray=new string[count];
	long long *scoreArray=new long long[count];
	//counters
	long long i=0;
	long long j=0;
	for(i=0; i<count; i++)	//inserting the values of userName.txt into the dynamic array
	{
		fin2>>nameArray[i];
	}
	for(i=0; i<count; i++)	//inserting the values of userScore.txt into the dynamic array
	{
		fin3>>scoreArray[i];
	}
	//temporary variables
	string tempN;
	long long tempS;
	for(i=0; i<count-1; i++)
	{
		for(j=0; j<count-1-i; j++)
		{
			if(scoreArray[j]<scoreArray[j+1])
			{
				tempS=scoreArray[j];
				scoreArray[j]=scoreArray[j+1];
				scoreArray[j+1]=tempS;
				tempN=nameArray[j];
				nameArray[j]=nameArray[j+1];
				nameArray[j+1]=tempN;
			}
		}
	}
	for(i=0; i<count; i++)	//runs a for loop from i=0 till less than count
	{
		fout<<nameArray[i]<<" "<<scoreArray[i]<<endl; //writes and combines nameArray and scoreArray into highscores.txt
	}
	fin.close();
	fin2.close();
	fin3.close();
	fout.close();
	//end of the function after closing all the fstreams
}
