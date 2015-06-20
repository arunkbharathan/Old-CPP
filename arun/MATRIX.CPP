#include<conio.h>
#include<iostream.h>
#include<process.h>

class matrix {
float A[100][100];
matrix operator +(matrix M);
matrix operator *(matrix M);
public:
void read();
void vdu();
};
int x,y,z;


void matrix::read()     {
cout<<"Enter-"<<endl<<endl<<"\t\t";
for(int i=0;i<x;++i)    {
for(int j=0;j<y;++j)    {
cin>>A[i][j];
cout<<"   ";            }
cout<<endl<<"\t\t";     }
cout<<endl<<endl<<endl; }


void matrix::vdu()      {
cout<<"Result-"<<endl<<endl<<"\t\t";
for(int i=0;i<x;++i)    {
for(int j=0;j<y;++j)    {
cout<<A[i][j]<<"   ";   }
cout<<endl<<"\t\t";     }
			}

void matrix::operator +(matrix M)      {
for(int i=0;i<x;++i)    {
for(int j=0;j<y;++j)    {
M3.A[i][j]=A[i][j]+M.A[i][j];
}}

void matrix::operator *(matrix M)      {
for(int i=0;i<x;++i)


void main()
{
matrix M1,M2,M3;
clrscr();
int c,i;
do {
cout<<"What kind of array operation do you want to perform +(1) or *(2) (EXIT[3]) -";
cin>>c;
clrscr();
 switch(c) {
case 1:
   cout<<"Enter size of row & column of matrix -";
   cin>>x>>y;
   clrscr();
   M1.read();
   M2.read();
   M3=M1+M2;
   M3.vdu();
   break;
case 2:
   cout<<"Enter size of row & column of matrix-";
   cin>>x>>y;i=x;
   clrscr();
   M1.read();
   cout<<"Enter size of row of 2nd matrix-";
   cin>>z;x=z;
   M2.read();x=i;
   M3=M1*M2;
   M3.vdu();
   break;
case 3:
  exit(1);
default:
  break;
  }
  }while(c!=3);   }
