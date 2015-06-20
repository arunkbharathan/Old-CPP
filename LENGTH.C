#include<conio.h>
int len(long int m)
{ int i;
for(i=0;m>0;i++)
  m=m/10;
  return i;
  }