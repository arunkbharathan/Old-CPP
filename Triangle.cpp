//Progam that gives all details of a Triangle given the lengths of its sides. 

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

main()
{
 clrscr();
 float a,b,c,S,D,A,B,C,Area,R;
 printf("Enter the lengths of the three sides of the triangle :

");
 scanf("%f%f%f",&a,&b,&c);

 S = (a+b+c)/2.0;        // S is the semiperimeter of the triangle
 D = S*(S-a)*(S-b)*(S-c);//D is the square of the area of the triangle
 if(D<=0)
 {
  printf("
The triangle cannot be formed");
  getch();
  exit(0);
 }

 if((a==b || b==c || c==a) && !(a==b && b==c && c==a))
// this complex logic is to eliminate interpretting a triangle with all
three
// sides equal as both isosceles and equilateral.
   printf("
The triangle is ISOSCELES

");
 if(a==b && b==c && c==a)
   printf("
The triangle is EQUILATERAL

");
 if(a!=b && b!=c && c!=a)
  printf("
The triangle is SCALENE

");

 Area = sqrt(D);
 R = (a*b*c)/(4.0*Area);
 printf("PERIMETER     = %.2f units
",(2.0*S));
 printf("AREA          = %.2f sq.units
",Area);
 printf("CIRCUM RADIUS = %.2f units
",R);
// using sine rule,we get...
 A = (180.0/3.1415926)*asin(a/(2.0*R));//  value of pi should be upto 7
 B = (180.0/3.1415926)*asin(b/(2.0*R));//  decimal places of accuracy and
also
 C = (180.0/3.1415926)*asin(c/(2.0*R));//  note that the 7th decimal place
is
		 		 		 		        //  6 and not 7 as it had to be if were
 if(A==90.0 || B==90.0 || C==90.0)     //  approximated to 7 decimal
places
  printf("
The triangle is RIGHT ANGLED
");
 if(A<90.0 && B<90.0 && C<90.0)
  printf("
The triangle is ACUTE ANGLED
");
 if(A>90.0 || B>90.0 || C>90.0)
  printf("
The triangle is OBTUSE ANGLED
");

 printf("
The angles are as follows :

");
 printf("A = %.2f degrees
",A);
 printf("B = %.2f degrees
",B);
 printf("C = %.2f degrees
",C);
 printf("
Where A,B,C stand for angles opposite to sides
%.2f,%.2f,%.2f",a,b,c);
 printf(" respectively
");


 getch();
 return 0;
}