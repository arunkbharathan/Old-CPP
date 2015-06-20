#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<iostream.h>
#include<process.h>
/**********************
*                     *
* FUNCTION PROTOTYPES *
*                     *
**********************/
void draw_calc();
void help();
void cal();
/**************************
*                         *
*  VARIABLES              *
**************************/
float x,y;
char ch;
/******************************
*  MAIN FUNCTION              *
******************************/


void main()
{
clrscr();
help();
int gr1=0,gr2;
initgraph(&gr1,&gr2,"e:\downloaded files\eudora attach");
draw_calc();
getch();
}

/***************************************************************************
*                                                                          *
*                       FUNCTION DEFINATION                                *
*                                                                          *
***************************************************************************/

void cal()
{
ch=0;
setfillstyle(SOLID_FILL,GREEN);
cout<<" 	      ";
gotoxy(25,9);
cin>>x;
cout<<"               ";
gotoxy(25,9);
cout<<"               ";
gotoxy(25,9);
ch=getch();
if (ch=='+')
{
floodfill(300,175,YELLOW);
gotoxy(25,9);
cout<<"               ";
gotoxy(25,9);
cin>>y;
cout<<"    	      ";
gotoxy(25,9);
cout<<x+y;
}
if (ch=='-')
{
floodfill(360,175,YELLOW);
gotoxy(22,9);
cout<<"                  ";
gotoxy(22,9);
cin>>y;
gotoxy(22,9);
cout<<"    	         ";
gotoxy(25,9);
int k=x-y;
cout<<k;
}
if (ch=='*')
{floodfill(300,215,YELLOW);
gotoxy(25,9);
cout<<"               ";
gotoxy(25,9);
cin>>y;
cout<<"    	      ";
gotoxy(25,9);
cout<<x*y;
}
if (ch=='/')
{
floodfill(360,215,YELLOW);
gotoxy(25,9);
cout<<"               ";
gotoxy(25,9);
cin>>y;

cout<<"    	      ";
gotoxy(25,9);
cout<<x/y;
}
if (ch=='ü')
{
floodfill(299,255,YELLOW);
gotoxy(25,9);
cout<<"               ";
gotoxy(25,9);
cin>>y;
cout<<"    	      ";
gotoxy(25,9);
double ans=pow(x,y);
cout<<ans;
}
if (ch=='l'||ch=='L')
{
floodfill(351,255,YELLOW);
cout<<"    	      ";
gotoxy(25,9);
double ans1=log10(x);
cout<<ans1;
}
if (ch=='x'||ch=='X')
{
closegraph();
clrscr();
exit(0);
}
else
{
getch();
draw_calc();
}

}



void draw_calc()
{
cleardevice();
setbkcolor(BLACK);
setcolor(YELLOW);
//main body
rectangle(150,100,400,300);
rectangle(145,95,405,305);
rectangle(160,120,392,150);
//row one
rectangle(165,165,190,190);
rectangle(205,165,230,190);
rectangle(245,165,270,190);
//row two
rectangle(165,205,190,230);
rectangle(205,205,230,230);
rectangle(245,205,270,230);
//row three
rectangle(165,245,190,270);
rectangle(205,245,230,270);
rectangle(245,245,270,270);
//print numbers
outtextxy(176,175,"7");
outtextxy(215,175,"8");
outtextxy(255,175,"9");
outtextxy(176,215,"4");
outtextxy(215,215,"5");
outtextxy(255,215,"6");
outtextxy(175,255,"1");
outtextxy(215,255,"2");
outtextxy(255,255,"3");
//operators buttons
rectangle(290,165,320,190);
rectangle(350,165,380,190);
rectangle(290,205,320,230);
rectangle(350,205,380,230);
rectangle(290,245,320,270);
rectangle(350,245,380,270);
//print operators
outtextxy(303,175,"+");
outtextxy(363,175,"-");
outtextxy(303,215,"*");
outtextxy(301,255,"xü");
outtextxy(363,215,"ö");
outtextxy(353,255,"log");
setfillstyle(SOLID_FILL,BROWN);
floodfill(152,102,YELLOW);
outtextxy(400,400,"MADE BY ANANT-HANDA");
cal();
}


void help()
{
cout<<"\n\n\n";
cout<<"\t\tWELCOME TO THE ULTIMATE CACLULATER ";
cout<<"\n\n\n\n";
cout<<"FEW POINTS TO USE THE CALCULATER. ";
cout<<"\n1.FIRST YOU NEED TO ENTER AN INTEGERS THEN THE OPERATOR AND IF REQUIRED THE SECOND INTEGER. ";
cout<<"\n2.DO NOT ENTER CHARECTER INSTEAD OF INTEGER AS IT MAY CAUSE THE PROGRAM TO STOP RESPONDING.";
cout<<"\n3.TO USE THE OPERATORS USE KEYPAD AND FOR LOG PRESS L AND FOR Xü PRESS ALT+252    FROM KEYPAD .";
cout<<"\n4.TO EXIT THE PROGRAM WHILE ENTERING THE OPERATOR ENTER X. ";
cout<<"\n5.IF YOU SEE THAT THE PROGRAM HAS STOPPED RESPONDING PRESS CTRL+ALT+DEL AND END TASK FOR THE PROGRAM.";
cout<<"\n\n\n\n\n\t\t\t\tMAIL YOU COMMENTS TO:: anant91@yahoo.com ";
getch();
}