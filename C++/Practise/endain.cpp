#include<iostream>
using namespace std;

 int main()
 {
   int a = 1;
  
   char* p = reinterpret_cast<char*>(&a);
  
   if(*p==1)
   cout << "The given integer is stored in Big Endain Format" << endl;

   else
   cout<<"The given integer is stored in little endain format" << endl;
   return 0;
}
     
