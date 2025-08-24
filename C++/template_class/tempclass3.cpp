#include<iostream>
#include<typeinfo>
using namespace std;

template<typename  T=int>

class A  
{

 
T a,b;

public:

A(T c, T d):a(c),b(d)

{

cout<<"The Parameterized constructor is called"<<endl;

cout<<"The Value of a and b is :"<<a <<" "<<b<<endl;

cout<<" The Type of values are : " <<typeid(T).name()<<endl;

}

T add ()
{
return a+b;
}
};


int main()

{

A <>a1(10,15);

a1.add();

cout<<"The value of addition is : " << a1.add()<< endl;
 
A <>a2(10.05f,12.06f);

a2.add();

cout<<"The value of addition is : " << a2.add()<< endl;

 return 0;

}
