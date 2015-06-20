#include<iostream.h>
#include<conio.h>
class student {
int roll;
char name[20];
int m1,m2,m3;
public:
void read();
void display();
char getgrade();
};

void student::read()
{ clrscr();
cout<<"ROLL NO:";cin>>roll;
cout<<endl<<"name:";cin>>name;
cout<<endl<<"mark 1:";cin>>m1 ;
cout<<endl<<"mark 2:";cin>>m2;
cout<<endl<<"mark 3:";cin>>m3;
}

char student::getgrade()
{ int p=(m1+m2+m3)/3;
if(p>=80)
return'a';
 else if(p>=60)
 return'b';
 else if(p>=50)
 return'c';
 else if(p>=40)
 return'd';
 else
 return'f';
 }

 void student::display()
 {cout<<endl<<endl<<"roll no:"<<roll<<endl;
  cout<<"name:"<<name<<endl;
  cout<<"mark 1:"<<m1<<endl;
  cout<<"mark 2:"<<m2<<endl;
  cout<<"mark 3:"<<m3<<endl;
  cout<<"grade:"<<getgrade();
  cout<<endl<<endl;
  }

  void main()
  { student s[20];
  for(int i=0;i<2;i++)
  s[i].read();
  for(i=0;i<2;i++)
  s[i].display();
  getch();
  }