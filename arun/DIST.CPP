#include<conio.h>
#include<iostream.h>


class dist{
int f,i;
public:
void read();
dist operator +(dist d);
void print();
};

dist d1,d2,d3;

void dist::read()
{cout<<"enter-";
cin>>f>>i;}

dist dist::operator +(dist d)
{ d3.i=i+d.i;
d3.f=f+d.f+ int (d3.i/12);
d3.i%=12;
return (d3);
}
void dist::print()
{
cout<<"total distance="<<f<<"\""<<i;
}
void main()
{ clrscr();
d1.read();
d2.read();
d3=d1+d2;
d3.print();
getch();
}