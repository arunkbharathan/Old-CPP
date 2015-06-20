#include<conio.h>
#include<iostream.h>
#include<dos.h>
void main()
{ clrscr();
for(int j=1;j<26;++j)
{for(int i=1;i<81;++i)
{gotoxy(i,j);
cout<<"A";
delay(62.5);
clrscr();
}}
getch();
}

