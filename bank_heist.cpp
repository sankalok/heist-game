#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct day{//struct for each day
  int members;
  int loot;
  int risk;
  day * next;
  
};

void addday(day * head, int m, int l,int r)// function to add a day 
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
void printday(day * head, int k)// fucntion to print the essential details of a day
{
  day * node = head;
  while(node->next!=NULL)
  {
    node = node->next;
  }
  cout<<endl;
  cout<<"####################################"<<endl;
  cout<<"Members - "<<node->members<<"  "<<"Loot - "<<node->loot<<"$   "<<"Day - "<<k<<"  Risk - "<<node->risk<<"%"<<endl;
}
bool findmember(string t[], string s, int m)//To find if a member has been sacrificed or not
{
  for(int i=0;i<m;i++)
  {
    if(t[i]==s)
    return true;
  }
  return false;
}

int main()//main function
{ //initialized all the variables at the starting
  cout<<"███╗░░░███╗░█████╗░███╗░░██╗███████╗██╗░░░██╗  ██╗░░██╗███████╗██╗░██████╗████████╗"<<endl;
  cout<<"████╗░████║██╔══██╗████╗░██║██╔════╝╚██╗░██╔╝  ██║░░██║██╔════╝██║██╔════╝╚══██╔══╝"<<endl;
  cout<<"██╔████╔██║██║░░██║██╔██╗██║█████╗░░░╚████╔╝░  ███████║█████╗░░██║╚█████╗░░░░██║░░░"<<endl;
  cout<<"██║╚██╔╝██║██║░░██║██║╚████║██╔══╝░░░░╚██╔╝░░  ██╔══██║██╔══╝░░██║░╚═══██╗░░░██║░░░"<<endl;
  cout<<"██║░╚═╝░██║╚█████╔╝██║░╚███║███████╗░░░██║░░░  ██║░░██║███████╗██║██████╔╝░░░██║░░░"<<endl;
  cout<<"╚═╝░░░░░╚═╝░╚════╝░╚═╝░░╚══╝╚══════╝░░░╚═╝░░░  ╚═╝░░╚═╝╚══════╝╚═╝╚═════╝░░░░╚═╝░░░"<<endl;
  int randmoney=0;
  int vaultopen = 0, vaultdate=0;
  int hackopen = 0, hackdate=0;
  int input, inp;
  int money=0, r=0,mos=0;
  int d=1;
  int leave=1;
  int mem = 7;
  int printmoney = 100000;
  int vaultmoney = 500000;
  int hackmoney = 500000;
  srand(time(NULL));//srand with time so that it is random every time
  day * head = NULL;
  day * first = new day;
  first->members = 7;//firdt node
  first->loot = 0;
  first->risk = 0;
  first->next = head;
  head = first;
  string team[7] = {"Tokyo", "Berlin", "Moscow", "Nairobi", "Stockholm", "Denver", "Rio"};//Team members
  cout<<"###############################################"<<endl;
  cout<<"##### Welcome to the Royal Mint of Spain   ####"<<endl;
  cout<<"##### You and your team have to perform    ####"<<endl;
  cout<<"##### The perfect heist. You have to steal ####"<<endl;
  cout<<"##### The maximum amount of money while    ####"<<endl;
  cout<<"##### Sarificing the least no. of players  ####"<<endl;
  cout<<"###############################################"<<endl;
  string op1 = "1. Print Money +";
  string op3 = "3. Open the Vault +";
  string op2 = "2. Hack the safe (Rio should be present) +";
  string le1 = "Leave the mint with a car (Tokyo should be present)";
  string le3 = "Leave the mint from the tunnel";
  string option[10]={"Free a hostage (+5%)(+5000$)", "Leak confidential documents (+5%)(+5000$)", "Spray money to cause commotion (+5%)(+5000$)","Cause a distraction (+5%)(+5000$)", "Place a listening bug (+10%)(+10000$)", "Bribe the police (+10%)(+10000$)", "Threaten the police (+10%)(+100000$)", "Threaten the hostages (+10%)(+10000$)","Kill a hostage (+15%)(+15000$)", "Detonate an explosive (+15%)(+15000$)"};//array to generate random options for the player
  string scene[10]={"Police found evidence against you", "Police placed a listening bug.", "Police caught one of your allies", "Police has decided to break in", "Police has decided to break in", "Open fire has been ordered", "One of the teammates requires medical help", "Tension grows among the team members", "You haven’t been able to contact the team since 24 hours", "One of the hostages has escaped"};// array to generate random scenarios for the player
  while(leave!=0 && r<100)//while player has not left and risk is not 100%
  {
    printday(head, d);//print the details of each day
    if(d%5==0 && printmoney>50000)//decreasing the printing capacity after every 5 days
    {
      printmoney -= 10000;
    }
    cout<<op1<<printmoney<<"$"<<endl;
    if(findmember(team, "Rio", 7) && hackopen==0)//If Rio is available and Safe is not already open
    {
      cout<<op2<<hackmoney<<"$"<<" (Will take "<<5-hackdate<<" more days)"<<endl;
    }  
    else if(hackopen==1)
    {
      cout<<"2. Safe is already opened"<<endl;
    }
    else if(!(findmember(team, "Rio", 7)) && hackopen==0)
    {
      cout<<"2. Rio is not present"<<endl;
    }
    if(vaultopen==0)// if vault is open or not
    {
      cout<<op3<<vaultmoney<<"$"<<" (Will take "<<3-vaultdate<<" more days)"<<endl;
    }
    else
    {
      cout<<"3. Vault already open"<<endl;
    }
    randmoney=(rand()%10+1)*10000;
    cout<<"4. Forex money availabe is +"<<randmoney<<"$"<<endl;
    cin>>input;
    if(input==1)//updating money 
    {
      money += printmoney;
    }
    else if(input==2 && findmember(team, "Rio", 7) && hackopen==0)//to add hack money to the total sum 
    {
      hackdate++;
      if(hackdate==5)
      {
        hackopen=1;
        money += hackmoney; 
      }
    }
    else if(input==2 && hackopen==1)
    {
      cout<<"Safe is open choose another option"<<endl;
      continue;
    }
    else if(input==2 && hackopen==0 && !findmember(team, "Rio", 7))
    {
      cout<<"Rio is not present choose another option"<<endl;
      continue;
    }
    else if(input==3 && vaultopen==0)//to add vault money to total money
    {
      vaultdate++;
      if(vaultdate==3)
      {
        vaultopen=1;
        money += vaultmoney;
      }
    }
    else if(input==3 && vaultopen==1)
    {
      cout<<"Vault is already open choose another option"<<endl;
      continue;
    }
    else if(input==4)//add forex money if user chooses so
    {
      money+=randmoney;
    }
    cout<<"###############################################"<<endl;
    cout<<"####  The Situation is Critical!!!!!!!!!!  ####"<<endl;
    cout<<"####  "<<scene[rand()%10]<<endl;//randomly create a scenario
    cout<<"####  To counter it you can :- "<<endl;
    int opt=rand()%8;//randomly create an option
    cout<<"1. "<<option[opt]<<endl;
    int opt2=rand()%8;//randomly create another option
    if(opt!=opt2)
    {
      cout<<"2. "<<option[opt2]<<endl;
    }
    while(opt==opt2)
    {
      opt2=rand()%8;
      if(opt!=opt2)
      {
        cout<<"2. "<<option[opt2]<<endl;
      }
    }
    cout<<"3. "<<option[rand()%2+8]<<endl;//randomly create an option
    if(findmember(team, "Tokyo", 7))//if tokyo is present
    {
      cout<<"4. "<<le1<<endl;
    }
    else//if tokyo is absent
    {
      cout<<"4. Tokyo is absent hence cannot escape through car (Don't choose this option)"<<endl;
    }
    if(findmember(team, "Moscow", 7) && d<9)
    {
      cout<<"5. "<<le3<<" (Moscow is required) (Will take "<<9-d<<" more days)"<<endl;
    }
    else if(!findmember(team, "Moscow", 7) && d<=9)
    {
      mos=1;
      cout<<"5. Tunnel cannot be dug since Moscow not present (Don't choose this option)"<<endl;
    }
    else if(d>=9 && mos==0)
    {
      cout<<"5. Tunnel ready you can leave"<<endl;
    }
    else if(d>=9 && mos==1)
    {
      cout<<"5. Tunnel cannot be dug since Moscow not present (Don't choose this option)"<<endl;
    }
    if(mem>1)//if members are more than 1
    {
      cout<<"6. Sacrifice a player "<<mem<<" available"<<endl;  
    }
    else
    {
      cout<<"6. Only one player left cannot sacrifice. (Don't choose this option)"<<endl;
    }
    if(money>=1000000)// if player has looted more than 1000000
    {
      cout<<"7. Reduce risk by 5% (by paying 1000000$)"<<endl;
    }
    cin>>inp;
    if(inp==1)//if user inputs 1
    {
      if(opt>=0 && opt<=3)
      {
        r+=5;
        money+=5000;
      }
      else
      {
        r+=10;
        money+=10000;
      }
    }
    if(inp==2)//if user inputs 2
    {
      if(opt2>=0 && opt2<=3)
      {
        r+=5;
        money+=5000;
      }
      else
      {
        r+=10;
        money+=10000;
      }
    }
    if(inp==3)//if user inputs 3
    {
      r+=15;
      money+=15000;
    }
    if(inp==4 && findmember(team, "Tokyo", 7))//if user inputs 4 and tokyo is present
    {
      leave=0;
    }
    if(inp==5 && mos==0)//if user inputs 5 and tunnel is dug
    {
      leave=0;
    }
    if(inp==6 and mem>1)//if user wishes to sacrifice a member and available members is greater than 1
    {
      int eliminate;
      string * memb= new string[mem];
      cout<<"Options to sacrifice :-"<<endl;
      int count=1;
      for(int i=0;i<7;i++)
      {
        if(team[i]!="null")
        {
          cout<<count<<". "<<team[i]<<endl;
          memb[count-1]=team[i];
          count++;
        }
      }
      cin>>eliminate;
      for(int i=0;i<7;i++)
      {
        if(team[i]==memb[eliminate-1])
        {
          team[i]="null";
          mem--;
        }
      }
      delete[] memb;
    }
    if(inp==7)//if user wishes to reduce risk
    {
      money-=1000000;
      r-=5;
    }
    d++;//day is added
    addday(head,mem,money,r);// new day created and data stored in it
  }
  money += mem*10000;//rewarded 10000 for remaining members
  d--;
  money += d*1000;
  cout<<"You stayed for "<<d<<" days"<<endl;//displays no. of days user was in
  cout<<"You looted "<<money<<"$"<<endl;// displays total money looted
  return 0; 
}

