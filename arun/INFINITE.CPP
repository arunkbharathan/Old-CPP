#include<fstream.h>
#include<conio.h>
void main()
{
clrscr();
char* g;
char f[12];
cout<<"____.____";
cin>>f;
ofstream write;
write.open(f,ios::binary);
cin>>g;
write<<g<<endl;
cin>>g;
write<<g<<endl;
write.close();
getch();
}
