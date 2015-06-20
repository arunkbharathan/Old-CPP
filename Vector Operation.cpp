
/*PROGRAM TO PERFORM VARIOUS OPERATION ON A VECTOR
		USING OPERATOR OVERLOADING*/

#include "Vector.cpp"

void main()
{
	system("cls");
	Vector A,B,C;
	int k,ch;
	char choice = 'y';
	do
	{
		if(choice == 'y' || choice == 'Y')
		{
			cout<<"
	INPUT VECTOR
";
			cout<<"
ENTER THE FIRST VECTOR.
";
			A.GetData();
			cout<<"
ENTER THE SECOND VECTOR.
";
			B.GetData();
		}

		system("cls");
		cout<<"
		PROGRAM FOR VECTOR OPERATIONS.
";
		cout<<"

First Vector(A)= "<<A<<"	Second Vector(B)= "<<B<<"

";
		cout<<"	1.Addition Of Two Vectors.
";
		cout<<"	2.Subtraction Of Two Vectors.
";
		cout<<"	3.Multiplication Of A Vector With The Scalar.
";
		cout<<"	4.Cross Product Of Two Vectors.
";
		cout<<"	5.Scalar(or Dot) Product Of Two Vectors.
";
		cout<<"	6.Negative Of Vectors.
";
		cout<<"	7.Exit
";
		cout<<"	
Enter The Choice. ";
		cin>>ch;
	    switch(ch)
		{
			case 1:
				cout<<"
ADDITION OF TWO VECTORS.
";
				C = A + B;
				cout<<"
The Value Of A+B Is: "<<C;
				break;
			case 2:
				cout<<"
SUBTRACTION OF TWO VECTORS.
";
				C = A - B;
				cout<<"
The Value Of A-B Is: "<<C;
				break;
			case 3:
				cout<<"
MULTIPLICATION OF A VECTOR WITH A SCALAR.
";
				cout<<"
Enter The Value Of The Scalar: ";
				cin>>k;
				C = A * k;
				cout<<"
The Value Of Ak Is (k Is the Scaler): "<<C;
				C = k * B;
				cout<<"
The Value Of kB Is (k Is the Scaler): "<<C;
				break;
			case 4:
				cout<<"
CROSS PRODUCT OF TWO VECTORS.
";
				C = A * B;
				cout<<"
The Value Of A*B(Cross Product) Is: "<<C;
				break;
			case 5:
				cout<<"
SCALAR(OR DOT) PRODUCT OF TWO VECTORS.
";
				A.DotProd(B);
				break;
			case 6:
				cout<<"
NEGATIVE OF A VECTOR.
";
				C = -A;
				cout<<"The Value Of -A Is: "<<C;
				C = -B;
				cout<<"
The Value Of -B Is: "<<C;
				break;
			case 7:
				return;
			default:
				cout<<"
WRONG CHOICE.
";
				break;
				getch();
		}
		cout<<"

DO YOU WANT TO ENTER A NEW VECTOR (y/n): ";
		cin>>choice;
		system("cls");
	}while(1);
}
//////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
                             //VECTOR.CPP

#include"Vector.h"


Vector::Vector():x(0),y(0),z(0)
{
	//cout<<"This Is A Default Constructor.";
}

Vector Vector::operator +(const Vector &v)const  //Addition
{
	Vector res;
	res.x = x + v.x;
	res.y = y + v.y;
	res.z = z + v.z;
	return res;
}

Vector Vector::operator -(const Vector &v)const  //Subtraction
{
	Vector res;
	res.x = x - v.x;
	res.y = y - v.y;
	res.z = z - v.z;
	return res;
}

Vector Vector::operator *(const int k)const  //Multiplication By Scalar
{
	Vector res;
	res.x = k * x;
	res.y = k * y;
	res.z = k * z;
	return res;
}

void Vector::GetData()			//Input The Vector
{
	cout<<"
Enter The Value Of x : ";
	cin>>x;
	cout<<"
Enter The Value Of y : ";
	cin>>y;
	cout<<"
Enter The Value Of z : ";
	cin>>z;
}

Vector operator *(int k,const Vector &v)
{
	return v * k;
}

Vector Vector::operator -()const   //Negative Of A Vector
{
	Vector res;
	res.x = -x;
	res.y = -y;
	res.z = -z;
	return res;
}

Vector Vector::operator *(const Vector &v)const //Cross (or Vector)
Product
{
	Vector res;
	res.x = (y * v.z) - (z * v.y);
	res.y = (z * v.x) - (x * v.z);
	res.z = (x * v.y) - (y * v.x);
	return res;
}

void Vector::DotProd(Vector v2)    //Dot(Or Scalar) Product
{
	int v1v2;
	v1v2 = (x * v2.x)+(y * v2.y)+(z * v2.z);
	cout<<"
The Value Of A.B Is: "<<v1v2;
}

ostream & Vector::Show(ostream & out)const
{
	if((x<0) && (y<0) && (z<0))
	out<<x<<"I"<<y<<"J"<<z<<"K";

	if((x<0) && (y<0) && (z>=0))
	out<<x<<"I"<<y<<"J+"<<z<<"K";

	if((x<0) && (y>=0) && (z<0))
	out<<x<<"I+"<<y<<"J"<<z<<"K";

	if((x<0) && (y>=0) && (z>=0))
	out<<x<<"I+"<<y<<"J+"<<z<<"K";

	if((x>=0) && (y<0) && (z<0))
	out<<x<<"I"<<y<<"J"<<z<<"K";

	if((x>=0) && (y<0) && (z>=0))
	out<<x<<"I"<<y<<"J+"<<z<<"K";

	if((x>=0) && (y>=0) && (z<0))
	out<<x<<"I+"<<y<<"J"<<z<<"K";

	if((x>=0) && (y>=0) && (z>=0))
	out<<x<<"I+"<<y<<"J+"<<z<<"K";

	return out;
}


////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
                       // VECTOR.H

#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

class Vector
{
private:
	int x,y,z;
public:
	Vector(int,int,int);
	Vector();
	void GetData();
	Vector operator+(const Vector &v)const;
	Vector operator-(const Vector &v)const;

	Vector operator*(const int k)const;		//Multiplication by Scalar
	Vector operator*(const Vector &v)const; //Cross Product
	Vector operator-()const;				//Negative Of A Scaler
	void DotProd(Vector);					//Dot Product

	ostream & Show(ostream & out)const;
	friend Vector operator*(const int k,const Vector &v);
	friend ostream & operator<<(ostream & out,const Vector &v)
	{
		v.Show(out);
	    return out;
	}
};



