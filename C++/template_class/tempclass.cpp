#include<iostream>
using namespace std;

template<typename  T>

T add(T a , T b) 
{

return a+b;

}

/*char add( char a, char b)
{

 cout<<"cannot add characters"<<endl;

return 0;

}
*/
int main()

{

 int c = add(10,15);
 cout<<"The value of add is : "<< c << endl;

float d = add(10.004f,15.005f);
cout<<"The value of add is : " << d<< endl;

char e = add('#','$');
cout<<"The value of add is : "<< e << endl;

 return 0;

}
