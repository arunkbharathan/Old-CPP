#include<conio.h>
#include<iostream.h>
#include<process.h>
class string
{ char A[100],B[100];
  int q,w,r,a;
  public:
  void read()
{
  clrscr();
  cout<<"Enter First String-";
  cin>>A;
  cout<<endl<<endl<<"Enter Second String-";
  cin>>B;
  cout<<endl<<endl;length();
  return;  }
  void copy()
  {
	int z,x;char c[100];
	for(z=0;z<=q;++z)
	{c[z]=A[z];}
	for(z=0;z<=w;++z)
	{A[z]=B[z];}
	for(z=0;z<=q;++z)
	{B[z]=c[z];}
	write();
	return;
	}
  private:
  void length()
      {
	for(q=0;A[q]!='\0';++q);
	for(w=0;B[w]!='\0';++w);
	compare();
	return;
	}
  void compare()
  {
	if(w!=q)
	{if(q>w)
		{r=1;return;}
		else
		 {r=2;return;}}

	for(a=0;a<=w;a++)
	{
		if(A[a]>B[a])
		{r=1;return;}
		if(B[a]>A[a])
		{
		r=2;return;}
		}
		return;
	}
  void write() {
	cout<<"\n\n";
	cout<<"                                  RESULT"<<endl;
	cout<<"                                 --------"<<endl<<endl<<endl;
	cout<<"The first string's length is- "<<q<<endl<<endl;
	cout<<"The second string's length is- "<<w<<"\n\n";
	if(r==1)
	{cout<<"The first is larger.\n\n";}
	if(r==2)
	{cout<<"The second is larger.\n\n";}
	if(r!=1&&r!=2)
	{cout<<"Both are same."<<"\n\n";}
	cout<<"Also swaped the strings."<<endl<<endl;
	cout<<A<<"\t"<<","<<"\t"<<B<<".";
	getch();   }
  };
	void main()
 {
	clrscr();
	string s;
	s.read();
	s.copy();
	exit(1);
 }







