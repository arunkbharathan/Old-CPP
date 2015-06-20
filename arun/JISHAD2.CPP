#include<conio.h>
#include<iostream.h>
class emp
{
		char *name;
		int accno;
		float bal;
	public:
		static int Howmany;
		void create();
		void deposit();
		void withdraw();
		void dispdata();
};
int emp::Howmany;
void emp::create()
{
	cout<<"Enter the name : ";
	cin>>name;
	accno=++Howmany;
	cout<<"Enter the Balance Amount : ";
	cin>>bal;
	if(bal>499)
		cout<<"Account Created\n";
	else
	{
		cout<<"Could not open the account\n";
		--Howmany;
	}
}
void emp::deposit()
{
	float a;
	cout<<"\nEnter the amount to deposit : ";
	cin>>a;
	if(a>0)
	{
		bal+=a;
		cout<<"Amount deposited\n";
	}
	else
		cout<<"Amount could not be deposited\n";

}
void emp::withdraw()
{
	float a;
	cout<<"\nEnter the amount to withdraw : ";
	cin>>a;
	if(a>0&&(bal-a)>499)
	{
		bal-=a;
		cout<<"Amount withdrawn";
	}
	else
		cout<<"Amount could not be deposited\n";

}
void emp::dispdata()
{
	cout<<"\nName    "<<name;
	cout<<"\nAcc No  "<<accno;
	cout<<"\nBalance "<<bal;
}
void main()
{
	emp e1[10];
	clrscr();
	while(emp::Howmany-11)
	{
		int ch;
		cout<<"\n\t1:Create\n\t2:Deposit\n\t3:Withdraw\n\t4:Display\n\t5:Exit\n\t  Current Employee is "<<emp::Howmany+1<<"\n\tEnter your choice\n";
		cin>>ch;
		if(ch==5)
			break;
		if(ch!=1&&!emp::Howmany)
		{
			cout<<"No Employees created";
			continue;
		}
		if(ch==1&&emp::Howmany==10)
		{
			cout<<"No creation again is allowed";
			continue;
		}
		switch(ch)
		{
			case 1:
				e1[emp::Howmany+1].create();
				break;
			case 2:
				e1[emp::Howmany].deposit();
				break;
			case 3:
				e1[emp::Howmany].withdraw();
				break;
			case 4:
				e1[emp::Howmany].dispdata();
				break;
			default:
				cout<<"Invalid choice";
		}
	}
}