#include<iostream>
using namespace std;

class Myclass
{

 public:

 Myclass()
 {

   cout << " My class Default Constrcutor Call ..." << endl;
 }

 ~Myclass()
 {

   cout << " Myclass Destructor Call ..." << endl;
 }

 void somefunction()
 {

  cout << " Some Function Call ... " << endl;
 }

};

 int main()
 {

 Myclass *ptr = new Myclass;
 
 Myclass *ptr2(ptr);
 
 Myclass *ptr3 = ptr2;

 ptr->somefunction();

 ptr2->somefunction();

 ptr3->somefunction();

 delete ptr;

 return 0;

 }

