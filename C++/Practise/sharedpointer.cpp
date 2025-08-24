#include<iostream>
#include<memory>
using namespace std;

class Myclass
{

 public:

 Myclass()
 {

   cout << " My class Default Constructor Call ..." << endl;
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

  shared_ptr<Myclass> ptr(new Myclass);
 
  shared_ptr<Myclass> ptr2(ptr);
 
  shared_ptr<Myclass> ptr3 = ptr2;

  cout<<" Use count is " <<  ptr.use_count() << endl;

  ptr->somefunction();

  ptr2->somefunction();

  ptr3->somefunction();

  ptr.reset();

  ptr2.reset();

  ptr3.reset();
 
  cout<<" Use count is " <<  ptr.use_count() << endl;

  return 0;

 }

