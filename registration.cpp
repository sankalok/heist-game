//registration.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "registration.h"
using namespace std;
//we return 0 once the registration of the user is successful
//we return 1 if the username already exist so the user needs to input again
//we return 2 if there is an error in opening the files
int registration()	//registration function
{
	string userName, input;
	cin>>userName;	//inputs the username
	ofstream fout;
	ifstream fin;
	fout.open("userName.txt", ios::app);
	fin.open("userName.txt");
	if(fout.fail())
	{
		cout<<"Error in opening File."<<endl;
		return 2;
	}
	if(fin.fail())
	{
		cout<<"Error in opening File."<<endl;
		return 2;
	}
	while(fin>>input)	//checks if username already exists or not
	{
		if(input==userName)
		{
			cout<<"Username already exists. Please try again."<<endl;
			return 1;
		}
	}
	fout<<userName<<endl;	//if its a unique username then we add the username to the .txt file
	fin.close();
	fout.close();
	return 0;
}
