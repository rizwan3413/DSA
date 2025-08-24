#include<iostream>
#include<string>
using namespace std;


bool operator==(string name1,string name2 )
{
 return !(name1.compare(name2));
}

int main()

{

 string r_name = "LOTUS";

 string c_name = "LOTUS";

 if(r_name == c_name)
 {
  
  cout << "Both the Strings are same ..." << endl;
 }

 else
 cout<<" Both are not equal..."<< endl;


 //if(r_name.compare(c_name)==0)
 
 return 0;
}
