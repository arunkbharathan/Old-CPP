#include<process.h>
#include<iostream.h>
#include<conio.h>

class atm
{long double ba,da,ca;
int acc;
char *nam;
public:
static int l;
void cre();
void dep();
void with();
void disp();
};
int atm::l;

void atm::cre()
{
char *n;float c;
clrscr();
if(l>9)
{cout<<"Limit is 10";return;}
 cout<<"------------------------------------------------------------------------------"<<endl;
 cout<<"                                     WELCOME"<<endl;
 cout<<endl<<endl<<endl;
 cout<<"Create An Account"<<endl;
 cout<<"_________________";
 cout<<endl<<endl<<endl;
 cout<<"Enter Your Name-";
 cin>>n;
 cout<<endl<<"Enter The Amount-";
 cin>>c;
 if(c>=500)
 { nam=n;ba=c;ca=0;da=0;
  acc=++l;
  cout<<endl<<endl<<"Account Created.";getch();
  }
  else
  {clrscr();
  cout<<endl<<endl<<"Unable TO Open Account:(The initial amount must be greater than 499.)";getch();
	}
	  return;}

	void atm::dep()
{ cout<<"Account Owner- "<<nam<<"."<<endl<<endl;
cout<<"Enter The Amount To Deposit-"<<endl<<endl;
 cin>>da;
 ba=ba+da;clrscr();
 cout<<endl<<endl<<"Amount Added Sucessfully." ;getch();
 }
 void atm::with()
 {float y;
 clrscr();
  cout<<"Account Owner- "<<nam<<"."<<endl<<endl;
 cout<<"Enter The Amount To Withdraw-"<<endl<<endl;
 cin>>y;
 ba=ba-y;
  if (ba>499)
  {ca=y;
  cout<<endl<<endl<<"Amount Withdrawn Sucessfully.";getch();}
  else
  { ba=ba+y;
  cout<<endl<<"Not Enough Balance-";getch();
  }
 }
  void atm::disp()
{ clrscr();
  cout<<"Account Owner- "<<nam<<"."<<endl<<endl;
  cout<<"Deposit Left-"<<ba;
  cout<<endl<<endl<<"Last Deposited Amount-"<<da;
  cout<<endl<<endl<<"Last Withdrawn Amount-"<<ca;
  getch();
  }
  void main()
{clrscr();
int t,x;
atm e1[10];
do {
clrscr();
 cout<<"------------------------------------------------------------------------------"<<endl;
 cout<<"                                     WELCOME"<<endl;
 cout<<endl<<endl<<endl;
 cout<<"                              1.CREATE ACC0UNT"<<endl;
 cout<<"                              2.DEPOSIT AMOUNT"<<endl;
 cout<<"                              3.WITHDRAW AMOUNT"<<endl;
 cout<<"                              4.DISPLAY AMOUNT"<<endl;
 cout<<"                              5.EXIT"<<endl;
 cout<<endl<<endl<<"Created Accounts-"<<atm::l<<" "<<"(Maximum-10)";
 cout<<endl<<endl<<endl<<"Input Any Choice-";
 cin>>t;
 switch(t)
 { case 1:
 e1[(atm::l)+1].cre();break;
 case 2:
 clrscr();
 if(atm::l==0)
 {cout<<"No Account Created.";getch();break;}
 cout<<"Enter acc no-";
 cin>>x;clrscr();
	if(x>atm::l)
  {cout<<"No Such Accounts.";getch();break;}
 e1[x].dep();break;

 case 3:
  clrscr();
	if(atm::l==0)
 {cout<<"No Account Created.";getch();break;}
 cout<<"Enter acc no-";
 cin>>x;clrscr();
 if(x>atm::l)
 {cout<<"No Such Accounts.";getch();break;}
 e1[x].with();break;

 case 4:
 clrscr();
  if(atm::l==0)
 {cout<<"No Account Created.";getch();break;}
 cout<<"Enter acc no-";
 cin>>x;  clrscr();
	if(x>atm::l)
  {cout<<"No Such Accounts.";getch();break;}
 e1[x].disp();break;

 case 5:
 cout<<endl<<"TERMINATING";
 exit(0);
 default:
 cout<<endl<<endl<<"INVALID KEY (Enter any 1 to 5) ";getch(); }
 }while(atm::l<11);
 exit;
 }








