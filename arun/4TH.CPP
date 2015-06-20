#include<iostream.h>
#include<conio.h>
#include<process.h>
void main()
{ clrscr();
long double a[16],k=0;long int c,d,b=0;
cout<<"ENTER THE DIGIT TO BE CONVERTED TO BINARY-";
cin>>c;
for(int j=c;c>0;c=j)
{ j=c/2;a[b]=(c-(2*j));b++;}
for(b=b-1;b>=0;b--)
{for(d=b;d>0;d--)
{a[b]*=10;}
k=a[b]+k;}
cout<<k;
getch();
exit;
}