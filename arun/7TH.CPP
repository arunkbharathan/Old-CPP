#include<conio.h>
#include<iostream.h>
#include<process.h>
class string
{ char A[100],B[100],C[200];
  int q,w,r,a;
  public:
  void read();
  void copy();
   string (){
  q=0;w=0;r=0;a=0;};
  private:
  void length();
  void compare();
  void write();
  void concat();
  };
  void string::read() {
  clrscr();
  cout<<"Enter First String-";
  cin>>A;
  cout<<endl<<endl<<"Enter Second String-";
  cin>>B;
  cout<<endl<<endl;
  length();
  return;  }

	void string::write() {
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
	cout<<"Concatanated the strings-"<<C<<endl<<endl;
	cout<<"Also swaped the strings."<<endl<<endl;
	cout<<A<<"\t"<<","<<"\t"<<B<<".";
	getch();   }

	void string::length() {
	for(q;A[q]!='\0';++q);
	for(w;B[w]!='\0';++w);
	compare();
	return;
	}

	void string::compare() {
	if(w!=q)
	{if(q>w)
		{r=1;concat();return;}
		else
		 {r=2;concat();return;}}

	for(a=0;a<=w;a++)
	{
		if(A[a]>B[a])
		{r=1;concat();return;}
		if(B[a]>A[a])
		{
		r=2;concat();return;}
		}
		concat();
		return;
	}
	void string::copy() {
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
	void string::concat() {
	   for(int l=0;l<=q;++l)
	    { C[l]=A[l]; }
	   for(int j=-1;j<=w;++j)
	   { C[l+j]=B[j+1]; }
	    return;  }

	void main()
 {
	clrscr();
	string s;
	s.read();
	s.copy();
	exit(1);
 }