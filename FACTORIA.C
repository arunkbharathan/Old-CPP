#include<stdio.h>

   double fact(int m)

{  int i;
   double f=1;
   for(i=1;i<=m;++i)
   f=(double)f*i;
   return f;
}
