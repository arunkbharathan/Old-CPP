#include <dos.h>
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
void main(void)
{     clrscr();
  struct dostime_t t;
  _dos_gettime(&t);
  printf("@$The current time is: %2d:%02d:%02d.%02d\n", t.hour, t.minute,
    t.second, t.hsecond);
       int x,y;
      printf("\nEnter time-");
      cin>>y;
 while(y!=t.second)
  {_dos_gettime(&t);
  cout<<t.second; };
sound(2500);
   sleep(2);
   nosound();
sound(4500);
   sleep(2);
   nosound();
    getch();
    return;


}


