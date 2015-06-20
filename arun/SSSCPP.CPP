#include<iostream.h>
#include<conio.h>
void main()
{clrscr();
int sum(int,int);
int a,b,c;
cin>>a>>b;
c=sum(a,b);
cout<<"\n"<<c;
getch();

}

int sum(int d,int g)
{ int f;
f=d+g;
return(f);
}