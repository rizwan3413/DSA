#include<iostream>
using namespace std;

/*Static,Const Cast,Re-Interpret Casting,Dynamic Cassting*/

/*Static Cast- Mostly used for Implicit Conversion */

class GooglePlus
{
 public:
 string Name;

 void print(string name) const
 {
  const_cast<GooglePlus*>(this)->Name = name;

  cout<< " This is GooglePlus Sample..." << endl;
 }
};

class Gmail:public GooglePlus
{
 public:

 void print1()
 {
  cout<< " This is Gmail Sample... " << endl;
 }
};

int main()
{
/* Static Cast
  GooglePlus *ptr = new GooglePlus;

  ptr->print();

  Gmail *p = new Gmail;
 
  ptr = p;
 
  ptr->print1();

//  p = static_cast<Gmail*>(ptr);

  p->print();
 
*/

 GooglePlus *ptr = new GooglePlus;

 ptr->print("Rizwan");
 
 const Gmail g1;
 
 Gmail g2;

 g2 = *const_cast<Gmail*>(&g1) 

 return 0;
}
 
  
 
