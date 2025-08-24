#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()

{
  vector<int> vect{1,2,1,4,1,6,1,8,1,1};
  
// count is used to cont the number of elements in the container

//returns zero if its there is no entry available 

cout<< count(vect.begin(),vect.end(),1)<<endl;


 return 0;

}
