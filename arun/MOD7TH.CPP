#include<conio.h>
#include<iostream.h>
#include<process.h>
class string
{ public:
char A[100],B[100],C[200],D[100];
  int q,r;

    string (char g[4]){
A[0]=g[0],A[1]=g[1],A[2]=g[2],A[3]=g[3],q=0,r=0,B[0]='\0',D[0]='\0';};

  void read();
  void swap(string &s);
  void length();
  void upper();
  void lower();
  void compare(string s);
  void write(string s);
  void concat(string s);
  };

   void string::read() {
  cout<<"Enter String-";
  cin>>A;
  cout<<endl<<endl;
  length();
  return;  }




	void string::write(string s) {
	cout<<"\n\n";
	cout<<"                                  RESULT"<<endl;
	cout<<"                                 --------"<<endl<<endl<<endl;
	cout<<"The first string's length is- "<<q<<endl<<endl;
	cout<<"The second string's length is- "<<s.q<<"\n\n";
	if(r==1)
	{cout<<"The first is larger.\n\n";}
	if(r==2)
	{cout<<"The second is larger.\n\n";}
	if(r!=1&&r!=2)
	{cout<<"Both are same."<<"\n\n";}
	cout<<"Concatanated the strings-"<<C<<endl<<endl;
  cout<<"After converting characters in both strings to uppercase-"<<B<<" / "<<s.B<<endl<<endl;
  cout<<"After converting characters in both strings to lowercase-"<<D<<" / "<<s.D<<endl<<endl;
	cout<<"Also swaped the strings."<<endl<<endl;
	cout<<A<<"\t"<<","<<"\t"<<s.A<<".";
	getch();   }

	void string::length() {
	for(q;A[q]!='\0';++q);
return;
	}

	void string::compare(string s) {
	if(s.q!=q)
	{if(q>s.q)
		{r=1;return;}
		else
		 {r=2;return;}}

	for(int j=0;j<=s.q;j++)
	{
		if(A[j]>s.A[j])
		{r=1;return;}
		if(s.A[j]>A[j])
		{
		r=2;return;}
		}

		return;
	}
	void string::swap(string &s) {
	int z,x;char c[100];
	for(z=0;z<=q;++z)
	{c[z]=A[z];}
	for(z=0;z<=s.q;++z)
	{A[z]=s.A[z];}
	for(z=0;z<=q;++z)
	{s.A[z]=c[z];}

	 return;
	}


	void string::concat(string s) {
	   for(int l=0;l<=q;++l)
	    { C[l]=A[l]; }
	   for(int j=-1;j<=s.q;++j)
	   { C[l+j]=s.A[j+1]; }
	    return;  }

	void string::upper()
	{
	for(int z=0;z<=q;++z)
	{if(A[z]>=97 && A[z]<=122)
	{B[z]=A[z]-32; }
	else
	B[z]=A[z];
	}B[z+1]='\0';}


		void string::lower()
	{
	for(int z=0;z<=q;++z)
	{if(A[z]>=65&& A[z]<=90)
	{D[z]=A[z]+32; }
	else
	D[z]=A[z];
	}D[z+1]='\o';}



	void main()
 {
	clrscr();

	string s1("THSS"),s2("IHRD");

	s1.read();
	s2.read();
	s1.compare(s2);
	s1.concat(s2);
	s1.upper();
	s2.upper();
	s1.lower();
	s2.lower();
	s1.swap(s2);
	s1.write(s2);
	exit(1);

 }