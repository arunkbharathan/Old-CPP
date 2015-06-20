#include<iostream.h>
#include<conio.h>
#include<process.h>


class time
{
int k;
int hh;
int mm;
int ss;
public:
void add(time g);
void read();
void print();
private:
void prnadd();
void  calc();
};


void time::read()
{ hh=0;mm=0;ss=0;
cout<<endl<<"enter a VALID time in the FORMAT hh,mm,ss:"<<endl;
cin>>hh>>mm>>ss;
}


void time::add(time g)
{  ss=ss+g.ss;
   mm=mm+g.mm;
   hh=hh+g.hh;
   hh=hh+(mm=mm+(ss)/60)/60;
   ss=ss%60;
   mm=mm%60;
   hh=hh%24;
   prnadd();
   return;
   }

void time::calc()
{
++ss;
if(ss==60)
{hh=hh+(mm=mm+(ss)/60)/60;}
ss=ss%60;
mm=mm%60;
hh=hh%24;
return;
 }


void time::prnadd()
{ cout<<endl<<endl<<"time after adding- "<<hh<<":"<<mm<<":"<<ss;
getch();
 }

void time::print()
{ calc();
cout<<endl<<"time is: "<<hh<<":"<<mm<<":"<<ss;
getch();
}

void main()
{ clrscr();
time s,d;
int p;
do
{clrscr();
 cout<<"\n                   1.INCREMENT";
 cout<<"\n                   2.ADD";
 cout<<"\n                   3.EXIT";
 cout<<"\n\nEnter Choice-";
cin>>p;
switch(p)
{ case 1:
s.read();
s.print();  break;
case 2:
s.read();
d.read();
s.add(d);
case 3:
cout<<endl<<"end";
exit; }
}while(p!=3);
}