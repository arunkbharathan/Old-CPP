#include<iostream.h>
#include<conio.h>
#include<process.h>

class kaal
{
int z;
int YY,MM,DD,hh,nn,ss;
public:
void read();
void print();
private:
void tcalc();
void dcalc();
void check();
};
void  kaal::check()
{if((YY<1)||YY>2500||DD<1||DD>31||nn>60||nn<0||ss>60||ss<0||MM>12||MM<1||hh>23||hh<0)
 {z=1;}
 return;
}
void kaal::read() {
cout<<"Enter -";
cin>>YY>>MM>>DD>>hh>>nn>>ss;
check();
if(z==1)
{cout<<endl<<"Invalid D/T Format";
getch();
exit(1);
}
return;
}
void kaal::tcalc()
{
++ss;
if(ss==60)
{hh=hh+(nn=nn+(ss)/60)/60;}
ss=ss%60;
nn=nn%60;
hh=hh%24;
if((hh==0)&&(nn==0)&&(ss==0))
{dcalc();}
return;
 }
 void kaal::dcalc() {
 int k,j,l;
 ++DD;
 switch (DD)
 { case 29:
 if(MM==2)
 {k=YY%4;j=YY%100;l=YY%400;
 if (k==0)
	{ if(j==0&&l==0)
	{	break;} }
	 else
		 {		DD=1;++MM;} }
	break;
    case 30:
    if(MM==2)
    {DD=1;++MM;}
      break;
      case 31:
      if(MM==4||MM==6||MM==9||MM==11)
      ++MM;DD=1;break;
    case 32:
    ++MM;DD=1;break;
    default:
       break; }
       if(MM==13)
       {++YY;MM=1;DD=1;}   }
void kaal::print()
{
tcalc();
cout<<endl<<YY<<":"<<MM<<":"<<DD<<":"<<hh<<":"<<nn<<":"<<ss;
return;
}
void main()
{
clrscr();
kaal s[1];
s[1].read();
s[1].print();
cout<<endl<<"end";
getch();
exit(1);
}
