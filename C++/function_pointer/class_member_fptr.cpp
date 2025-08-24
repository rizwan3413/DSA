#include<iostream>
using namespace std;

class A
{

public:

static int d;

static void add(int a,int b)
{

cout<<"The Value of a is  "<<a<<"\nThe Value of b is"<<b<<"\nThe result is"<<a+b;

}

void subtract(int a,int b)
{

cout<<"\nThe Value of a is"<<a<<"\nThe Value of b is"<<b<<"\nThe result is"<<a-b<<endl;

}

};

int A::d;

int main()

{

void(A::*fp)(int,int);

void(*gp)(int,int);

gp = &A::add;

A a1,a2;

(*gp)(10,15);

fp =&A::subtract;

(a1.*fp)(15,10);

cout<<"\nAddress of object1:"<<&a1.d<<endl;
cout<<"\nAddress of object2"<<&a2.d<<endl;
cout<<"\nAddress of static variable:"<<&A::d<<endl;

return 0;
}



