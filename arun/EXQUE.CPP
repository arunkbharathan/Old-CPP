#include<conio.h>
#include<iostream.h>

int i=0;
void sum(int i)
{ cout<<endl<<i<<";"<<::i<<",";
i=4; }
void main()
{ clrscr();
int i=5;
sum(i);
cout<<i;
getch();
}