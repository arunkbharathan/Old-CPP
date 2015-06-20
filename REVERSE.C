#include<stdio.h>
#include<conio.h>
void main()
{
long int n,s;
  int l;
  clrscr();
  printf("Enter an integer- ");
  scanf("%ld",&n);
for(s=0;n>0;n=n/10)
 {l=n%10;
  s=l+s*10;
}
  printf("\nThe reverse is  - %ld",s);
  getch();
  }
