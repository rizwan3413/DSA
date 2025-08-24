#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

void print(map<int,int> a);

int main()

{

    map<int,int> a;
    
    a[0] = 1;
    
    a[1] = 13;
    
    a[2] = 14;
    
    a[3] = 15;

    pair<int,int> b;

    b.first = 4;
    b.second =15;
   
   a.insert(b);
   
   print(a);
 
//   map<int,int> :: iterator itr;
/*
  if( a.end() ==find(a.begin(),a.end(),4))

    cout<< "The Key is not present in the map"<<endl;
    
   else 

   cout<<"Key is present in map"<<endl;

*/

 // cout<<"Pair:(Key,Value)("<< itr->first <<","<< itr->second<<")"<<endl;
     
return 0;

}

 void print(map<int,int> a)

{
   
     map<int,int> :: iterator itr = a.begin();


   while(itr!=a.end())

{
   cout<<"The begining pair is "<<itr->first<<endl;

   cout<<"Pair:(Key,Value)("<< itr->first <<","<< itr->second<<")"<<endl;

itr++;

}

}

  
