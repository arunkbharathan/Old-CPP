#include<stdio.h>
#include<conio.h>
void main()
{ clrscr();
char c;
FILE *f1,*f2;
f1 = fopen("MESSAGE.txt","r");
f2 = fopen("ENCODED.txt","w");
while((c=getc(f1)) != EOF)
putc(c+110,f2);
fclose(f1);
fclose(f2);
printf("\nMessage Encoded.\n\n\nPress any key.");
getch();
}