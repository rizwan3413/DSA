#include<iostream>
#include<typeinfo>
using namespace std;

template<typename  T1,typename T2>

void add(T1 a , T2 b) 
{

cout<<"The Data type of a is :" << typeid(T1).name()<<endl;

cout<<"The Data type of b is : "<<typeid(T2).name()<<endl; 

cout<<"The Addition result is :"<<a+b<<endl;

}


int main()

{

  add(10,15.01f);

 add(10,15.005f);

 add('#','10');

 return 0;

}
