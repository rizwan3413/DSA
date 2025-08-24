#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



void print(int a)
{

    cout<< a << " ";

}

int main()

{
  vector<int> vect{1,2,3,2,5,2,7,8,2,10};
  
  for_each(vect.begin(),vect.end(),print);

  cout << "\n";
  
  replace(vect.begin(),vect.end(),2,11);

  for_each(vect.begin(),vect.end(),print);
  
 return 0;

}

