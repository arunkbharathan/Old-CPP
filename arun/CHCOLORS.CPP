#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
#include<dos.h>
void main()
{ clrscr();
int z,x,c,v,j,a,s,d,f,q,w,e,r;
randomize();
df:
for(j=0;j<16;j++)
{clrscr();
textcolor(j);
z=rand() %10;
x=rand() %10;
c=rand() %10;
v=rand() %10;
a=rand() %10;
s=rand() %10;
d=rand() %10;
f=rand() %10;
q=rand() %10;
w=rand() %10;
e=rand() %10;
r=rand() %10;
cout<<" "<<x<<c<<v<<z<<x<<c<<v<<c<<z<<x<<x<<c<<v<<x<<c<<v<<v<<"  "<<a<<s<<d<<f<<a<<s<<d<<f<<a<<f<<s<<a<<d<<f<<a<<s<<d<<f<<"  "<<w<<e<<r<<q<<"        "<<e<<r;
cout<<q<<w<<"  "<<x<<d<<v<<x<<d<<x<<d<<"      "<<x<<q<<d<<v<<endl;
cout<<" "<<z<<c<<v<<c<<v<<x<<c<<c<<c<<x<<z<<z<<c<<x<<z<<c<<z<<"  "<<s<<d<<f<<d<<s<<f<<a<<s<<f<<d<<s<<f<<d<<s<<f;
cout<<d<<s<<s<<"  "<<w<<r<<q<<w<<"        "<<w<<q<<r<<e<<"  "<<x<<d<<v<<v<<""<<x<<q<<d<<"      "<<x<<d<<v<<x<<endl;
cout<<" "<<c<<x<<v<<c<<"         "<< z<<x<<c<<c<<"  "<<s<<d<<f<<a<<"          " <<f<<d;
cout<<s<<a<<"  "<<w<<e<<r<<w<<"        "<<r<<w<<q<<e<<"  "<<d<<x<<v<<d<<" "<<q<<x<<v<<"     "<<q<<d<<x<<v<<endl;
cout<<" "<<v<<x<<c<<v<<"         "<< z<<c<<z<<c<<"  "<<f<<d<<s<<a<<"          "<<d<<s<<f<<a<<"  "<<q<<w<<e<<r<<"        "<<w;
cout<<q<<e<<r<<"  "<<d<<v<<x<<q<<"  "<<v<<d<<x<<"    "<<x<<d<<v<<q<<endl;
cout<<" "<<v<<x<<z<<c<<"         "<< z<<x<<c<<z<<"  "<<s<<a<<f<<a<<s<<d<<s<<f<<a<<s<<d<<f<<a<<s<<s<<f<<s<<d<<"  "<<e;
cout<<q<<w<<r<<"        "<<e<<w<<q<<r<<"  "<<x<<d<<v<<x<<"   "<<x<<q<<v<<"   "<<q<<x<<d<<v<<endl;
cout<<" "<<x<<c<<z<<v<<x<<v<<x<<c<<v<<x<<c<<v<<z<<c<<x<<c<<v<<"  "<<f<<s<<a<<s<<a<<d<<s<<f<<s<<a<<d<<a;
cout<<s<<f<<a<<s<<d<<f<<"  "<<q<<r<<e<<w<<"        "<<w<<e<<q<<r<<"  "<<x<<d<<q<<v<<"    "<<q<<d<<v<<"  "<<x<<q<<x<<d<<endl;
cout<<" "<<z<<x<<c<<x<<v<<c<<v<<z<<c<<x<<x<<c<<v<<c<<v<<x<<z<<"  "<<a<<d<<f<<d<<""<< a<<s<<d<<f<<c<<"           "<<e<<w;
cout<<e<<r<<"        "<<w<<q<<e<<r<<"  "<<x<<d<<v<<q<<"     "<<d<<q<<x<<" "<<x<<v<<x<<q<<endl;
cout<<" "<<z<<c<<x<<c<<"         "<<z<<x<<c<<v<<"  "<<a<<d<<s<<f<<"    "<<r<<s<<d<<f<<a<<"       "<<r<<w<<e<<r<<q<<w<<r<<q<<w<<r<<w<<e<<r;
cout<<w<<r<<q<<"  "<<x<<d<<v<<x<<"      " <<q<<x<<d<<""<<x<<v<<v<<d<<endl;
cout<<" "<<z<<x<<c<<v<<"         "<< z<<c<<v<<v<<"  "<<f<<d;
cout<<s<<d<<"        "<<d<<s<<f<<a<<x<<s<<"  "<<q<<w<<e<<r<<q<<w<<r<<e<<r<<w<<e<<q<<r<<e<<q<<w<<"  "<<q<<x<<v<<d<<"       " <<q<<x<<v<<x<<d<<v<<endl;
delay(60); }
j=0;
goto df;
}