#include<iostream>
using namespace std;

class Test
{

 public:

 int x;
 

 void function()
 {

  cout << "Some function call ..." << endl;
 }

};

template<typename T>
class Shared_pointer
{

 public:
 
 T *ptr;

 static int count;

 Shared_pointer(T *a):ptr(a){
 count++;
 cout << "Constructor Call ..." << endl;}
 
 Shared_pointer(const Shared_pointer& obj)
 {
   //obj.*ptr = ptr;
   count++;
   cout<<" Copy Constructor Call..."<< endl;
 }

/* Shared_pointer& operator = (const Shared_pointer& obj)
 {
  // obj.*ptr = ptr;
  
   cout<<" Assignment Operator Call..."<<endl;
   use_count++;
 }
*/

 int use_count()
 {

  return count;
 }

 void reset()
 {
   ptr = nullptr;
   count--;
   cout<< count <<endl;
 }

 T*  operator ->()
 {
    return ptr;
 }
 
  ~Shared_pointer()

    {
      if(count==0)
      delete ptr;
      
      count--;
      cout << "Destructor call" << endl;
    }
};

template<typename T>
int Shared_pointer<T>::count = 0;

int main()
{

 Shared_pointer<Test> p1(new Test);

 
 Shared_pointer<Test> p2(p1);
 
 
 Shared_pointer<Test> p3 = p1;

 p1->function();
 
 p2->function();

 p3->function();

 cout<< p1.use_count()<<endl;

 p1.reset();

 return 0;

}

 

