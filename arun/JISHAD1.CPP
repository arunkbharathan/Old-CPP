 #include<conio.h>
#include<iostream.h>
class Time
{
	int hh,mm,ss;
public:
	void add(Time);
	void read();
	void PrintTime();
};
void Time::read()
{
	while(1){
		cout<<"\nEnter hh,mm,ss ";
		cin>>hh>>mm>>ss;
		if(hh>23||mm>59||ss>59||hh<0||mm<0||ss<0)
		{
			cout<<"Invalid Time";
			continue;
		}
		else
			break;
	}
	cout<<"\nRead Successful";
}
void Time::PrintTime()
{
cout<<"\n"<<hh<<":"<<mm<<":"<<ss;
}
void Time::add(Time T)
{
	hh+=T.hh+(mm+=T.mm+(ss+=T.ss)/60)/60;
	hh%=24;
	mm%=60;
	ss%=60;
}
void main()
{
	clrscr();
	Time t1,t2;
	t1.read();
	t2.read();
	t1.add(t2);
	t1.PrintTime();
	getch();
}