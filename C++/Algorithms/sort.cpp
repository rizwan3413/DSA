#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void print(int a)
{

    cout<<"the Value of a is:"<<a<<endl;

}

void even(int b)

{

 if(b%2==0)
 
 cout<<"The number is Even "<< b  << endl;

}

bool mysort(int c,int d)
{

 return c > d;
}


int main()

{
  vector<int> vect{1,2,3,4,5,6,7,8,9,10};
  
 for_each(vect.begin(),vect.end(),print);

 sort(vect.begin(),vect.end(),mysort);

 for_each(vect.begin(),vect.end(),print);

 return 0;

}
