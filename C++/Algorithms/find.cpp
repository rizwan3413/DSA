#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()

{
  vector<int> vect{1,2,3,4,5,6,7,8,9,10};

 vector<int>::iterator itr;
  
 itr = find(vect.begin(),vect.end(),100);
 
 if(itr == vect.end())

 cout<<"The element is not present"<<endl;

 else 

 cout<<"The searched value is : " << *itr<<endl;

 return 0;

}
