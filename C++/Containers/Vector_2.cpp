#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


void print(vector<int> c)

{

vector<int> ::iterator itr= c.begin();

int i = 0;
while(itr!=c.end())

{
  

cout<<"Elements at "<<i<<" Value is " << *itr << endl;

itr++;
i++;

}

}


int main()

{

vector<int> b{10,9,8,7,6,5,4,3,2,1};

cout<<" The Vector before sorting is"<< endl;

print(b);

sort(b.begin(),b.end());

cout<<" The Vector after sorting is"<<endl;

print(b);


vector<int> :: iterator d;

d = max_element(b.begin(),b.end());

cout<<"The value of maximum in Vector is  "<<*d<<endl;

d = min_element(b.begin(),b.end());

cout<< "The value of minimum in vector is  " << *d<< endl;

return 0;

}

