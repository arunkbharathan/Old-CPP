#include<conio.h>
#include<iostream.h>
#include<process.h>
void main()
{clrscr();
int b=0,c=0;long double i=0,a=0;
cout<<"enter a number-";
cin>>a;
for(i=10e18;a>0;i=(i/10))
{b=(a/i);
c=c +b;
a=a-(i*b);}
cout<<endl<<"the sum is-"<<c;
getch();
exit;
}