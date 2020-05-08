#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct day{
  int members;
  int loot;
  int risk;
  day * next;
  
};

void addday(day * head, int m, int l,int r)
{
  day * p = new day;
  p->members = m;
  p->loot = l;
  p->risk = r;
  day * temp = head;
  while(temp->next!=NULL)
  {
    temp=temp->next;
  }
  p->next=temp->next;
  temp->next = p;
}
void printday(day * head, int k)
{
  day * node = head;
  while(node->next!=NULL)
  {
    node = node->next;
  }
  cout<<"####################################"<<endl;
  cout<<"Members - "<<node->members<<"  "<<"Loot - "<<node->loot<<"$   "<<"day - "<<k<<" risk - "<<node->risk<<"%"<<endl;
}
bool findmember(string t[], string s, int m)
{
  for(int i=0;i<m;i++)
  {
    if(t[i]==s)
    return true;
  }
  return false;
}

int main()
{
  int vaultopen = 0, vaultdate=0;
  int hackopen = 0, hackdate=0;
  int input;
  int money=0;
  int d=1;
  int leave=1;
  int mem = 7;
  int printmoney = 100000;
  int vaultmoney = 500000;
  int hackmoney = 500000;
  srand(time(NULL));
  day * head = NULL;
  day * first = new day;
  first->members = 7;
  first->loot = 0;
  first->risk = 0;
  first->next = head;
  head = first;
  string team[7] = {"Tokyo", "Berlin", "Moscow", "Nairobi", "Stockholm", "Denver", "Rio"};
  cout<<"####################################"<<endl;
  cout<<"Welcome to the royal mint of Spain "<<endl;
  cout<<"You and your team have to perform "<<endl;
  cout<<"The perfect heist. You have to steal"<<endl;
  cout<<"the maximum amount of money while "<<endl;
  cout<<"sarificing the least no. of players"<<endl;
  cout<<"####################################"<<endl;
  string op1 = "1. Print Money ";
  string op3 = "3. Open the Vault ";
  string op2 = "2. Hack the safe (Rio should be present) ";
  string le1 = "Leave the mint with a car (Tokyo should be present)";
  string le2 = "Leave the mint with hostages(No money earned)";
  string le3 = "Leave the mint from the tunnel";
  string option[10]={"Free a hostage (5%)(+5000$)", "Leak confidential documents (5%)(+5000$)", "Spray money to cause commotion (5%)(+5000$)","Cause a distraction (5%)(+5000$)", "Place a listening bug (10%)(+10000$)", "Bribe the police (10%)(+10000$)", "Threaten the police (10%)(+100000$)", "Threaten the hostages (10%)(+10000$)","Kill a hostage (15%)(+15000$)", "Detonate an explosive (15%)(+15000$)"};
  while(leave!=0 && mem>0)
  {
    printday(head, d);
    if(d%5==0)
    {
      printmoney -= 10000;
    }
    cout<<op1<<printmoney<<"$"<<endl;
    if(findmember(team, "Rio", 7) && hackopen==0)
    {
      cout<<op2<<hackmoney<<"$"<<"(Will take "<<5-hackdate<<" more days)"<<endl;
    }  
    else if(hackopen==1)
    {
      cout<<"2. Safe is already opened"<<endl;
    }
    else if(!(findmember(team, "Rio", 7)))
    {
      cout<<"2. Rio is not present"<<endl;
    }
    if(vaultopen==0) 
    {
      cout<<op3<<vaultmoney<<"$"<<"(Will take "<<3-vaultdate<<" more days)"<<endl;
    }
    else
    {
      cout<<"3. Vault already open"<<endl;
    }
    cin>>input;
    if(input==1)
    {
      money += printmoney;
    }
    else if(input==2 && findmember(team, "Rio", 7) && hackopen==0)
    {
      hackdate++;
      if(hackdate==5)
      {
        hackopen=1;
        money += hackmoney; 
      }
    }
    else if(input==3 && vaultopen==0)
    {
      vaultdate++;
      if(vaultdate==3)
      {
        vaultopen=1;
        money += vaultmoney;
      }
    }
    d++;
    addday(head,mem,money,0);

  }
  return 0;
  
}