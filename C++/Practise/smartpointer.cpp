#include<iostream>
#include<memory>
using namespace std;

class Test
{

 public :

 int x;

};

template<typename T>
class Sp
{

 public:

 T *ptr;


 Sp(T* a):ptr(a){}
 
 ~Sp()
 
 {
    cout<<" Destructor Call"<< endl;
    delete ptr;
 }

 Sp& operator=(const Sp&) = delete;

 Sp (const Sp&) = delete;

 T* operator ->()
 {
    return ptr;
 }

 T& operator * ()

 {
    return *ptr;
 }
 
};

int main()

{
   Sp<Test> ptr(new Test);

  //ptr.operator->() .This will return a memory address, again on that memory address we are calling arrow operator//
 
   ptr->x = 10;

   (*ptr).x = 50;

   cout << ptr->x << endl;
   
   return 0;
}
 

 // Sp<Test> p(new Test);

 // Sp<Test> q = p;

 // p->x

