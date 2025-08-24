#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void even(int b)

{

 if(b%2==0)
 
 cout << b <<" is Even number "<< endl;

}


int main()

{
  vector<int> vect{1,2,3,4,5,6,7,8,9,10};
  
 for_each(vect.begin(),vect.end(),even);


 return 0;

}
