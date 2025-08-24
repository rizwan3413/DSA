#include<iostream>
#include<stdlib.h>

using namespace std;

int main()

{
 int account_number = 537285;

 string user_id = "3413";
  
 account_number = atoi(user_id.c_str());

 float salary = (account_number/2.0);
 
 cout<<" \n The acccount number is : " << account_number << endl;
 
 cout.precision(8);
 cout<<" \n The salary is : " << salary << endl;

 float bonus = 5000.265486;

 if(bonus>5000.265487f)

 {

  cout<<" You will get bonus" << endl;
 }

 else
 cout<<" You will get bonus next year"<<endl;

 

 return 0;
}

