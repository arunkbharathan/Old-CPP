#include<dos.h>
char far *ch=(char far *)0xB8000000;
char l[]="kuttath",i=0,j=0;
void interrupt(*prev)();
void interrupt our();
void main()
{
  prev=getvect(8);
  setvect(8,our);
  keep(0,1000);
  }
  void interrupt our()
  {
  *(ch+3800+i*2)=l[i++];
  i%=7;
  *(ch+3801+i*2)=j++;
  (*prev)();
  }