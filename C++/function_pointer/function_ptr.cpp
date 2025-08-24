#include<iostream>
using namespace std;

//Vendor Code//

typedef void(*fp)(int,int); // typedef shared_ptr itr shared_p

void compute(fp var,int big,int small)
{

var(big,small);
}

//Consumer code is below//


void add(int a,int b)
{

cout<<"The Value of a is  "<<a<<"\nThe Value of b is"<<b<<"\nThe result is"<<a+b;

}

void subtract(int a,int b)
{

cout<<"\nThe Value of a is"<<a<<"\nThe Value of b is"<<b<<"\nThe result is"<<a-b<<endl;

}

int main()
{

/*
fp var = &add;// void(*fp)(int,int) = &add //fp behaves  as datatype while doing a type def

var(15,10);

var =&subtract;

var(15,10);
*/

compute(&add,10,15);
compute(&subtract,15,10);

return 0;
}






