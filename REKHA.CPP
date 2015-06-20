#include<fstream.h>
#include<iostream.h>
#include<conio.h>
struct account
{
int accno;
char name[20];
float bal;
}


  void main()
{clrscr();
struct account acc;
int choice;
 cout<<"------------------------------------------------------------------------------"<<endl;
 cout<<"                                     WELCOME"<<endl;
 cout<<endl<<endl<<endl;
 cout<<"                              1.CREATE ACC0UNT"<<endl;
 cout<<"                              2.WITHDRAW AMOUNT"<<endl;
 cout<<"                              3.DEPOSIT AMOUNT"<<endl;
 cout<<"                              4.DISPLAY DETAILS"<<endl;
 cout<<"                              5.EXIT"<<endl;
 cout<<endl<<endl<<endl<<"Input Any Choice-";
 cin>>choice;
 ofstream outfile;
 outfile.open("account.dat");
 ifstream infile("account.dat");
switch(choice)
 { case 1:
 clrscr();
cout<<"\nEnter acc number-";
cin>>acc.accno;
cout<<"\nEnter name-";
cin>>acc.name;
cout<<"\Enter balance amount-";
cin>>acc.bal;
outfile. write((char*)&acc,sizeof(account));
outfile.close;
break;
 case 2:
 float withdrawl;
 cout<<"\nEnter withdrawl-";
 cin>>withdrawl;
 acc.bal=acc.bal-withdrawl;
  outfile. write((char*)&acc,sizeof(account));
outfile.close;
 break;

 case 3:
 float deposit;
 cout<<"\nEnter deposit-";
 cin>>deposit;
 acc.bal=acc.bal+deposit;
 outfile.write((char*)&acc,sizeof(account));
outfile.close;
 break;

 case 4:
 infile.read((char*)&acc,sizeof(account));

 cout<<"\no Account Number is-"<<acc.accno;
cout<<"\nName is-"<<acc.name;
cout<<"\nBalance is-"<<acc.bal;
infile.close;
break;
 case 5:
 break;
 default:
 cout<<endl<<endl<<"INVALID KEY (Enter any 1 to 5) ";getch(); }
  return(0);
 }








