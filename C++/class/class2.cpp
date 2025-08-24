#include<iostream>
using namespace std;

class A

{

public:

 const int a;

 int d;

 int &b;

 static int c;

 A(int,int,int&);

};

int A :: c = 5;

A::A(int x,int y,int& z):a(x),d(y),b(z){}

int main()

{

 int e = 20; 

 A a1(10,20,e);
 
 cout <<"The value of a is :  " <<a1.a<<endl;

 cout<<"The value of b is :   " <<a1.b << endl;

 cout<<"The value of c is :   " <<a1.c << endl;

 cout<<"The value of d is :   " <<a1.d << endl;

 return 0;
}


