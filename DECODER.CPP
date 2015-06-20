#include<stdio.h>
#include<conio.h>
void main()
{ clrscr();
char c;
FILE *f1,*f2;
f1 = fopen("ENCODED.txt","r");
f2 = fopen("DECODED.txt","w");
while((c=getc(f1)) != EOF)
putc(c-110,f2);
fclose(f1);
fclose(f2);
printf("\nMessage Decoded.\n\n\nPress any key.");
getch();
}