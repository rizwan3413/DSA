#include<iostream>
#include<vector>
using namespace std;

int main()
{


vector <int> a;

a.push_back(15);

a.push_back(25);

a.push_back(30);


for(int i=0;i<a.size();i++)

{

cout<<"Element at"<<i<<" "<<"is"<<a[i]<<endl;

}

cout<<"max elements of type int :"<<a.max_size()<<endl;



return 0;

}


