#include<stdio.h>
#include<conio.h>
void main()
{ clrscr();
char c='a';
float k=0;
//int h=1;
FILE *f2;
f2 = fopen("MESS10MB.txt","w");
while(k != 10485760)
{putc(c,f2);
//putc('\n',f2);
k++;
}
putc(EOF,f2);
fclose(f2);
printf("\nFile Created.\n\n\nPress any key.");
getch();
}