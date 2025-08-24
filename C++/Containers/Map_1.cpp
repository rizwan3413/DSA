#include<iostream>
#include<map>


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

  
