#include<conio.h>
#include<stdio.h>
void main()
{
int c=0;
float vcost,t,avgcost,range,l,s;
 clrscr();
 Again:
printf("\nEnter cost if over press 0 - ");
scanf("%f",&vcost);
if(vcost<=0)
{goto out;}
c++;
if(c==1)
{l=vcost;s=vcost;}
if(vcost>l)
l=vcost;
if(vcost<s)
s=vcost;
t+=vcost;
 goto Again;

out:
avgcost=t/c;
range=l-s;
printf("\nThe avgcost is - %f\nThe range is - %f",avgcost,range);
getch();
}
