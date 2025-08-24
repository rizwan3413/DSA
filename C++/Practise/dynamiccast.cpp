#include<iostream>
using namespace std;

class Google
{
 public:
 
 virtual void show() = 0;

};

class Gmail :public Google
{
 public:

 void show()
{
 cout << "I'm Gmail " << endl;
}
};

class GoogleDrive:public Google
{
 public:
 void show()
{
 cout<<"I'm Google Drive" << endl;
}
};

void findproduct(Google* ptr)
{
  Gmail *ptr1 = dynamic_cast<Gmail*>(ptr);
  GoogleDrive *p = dynamic_cast<GoogleDrive*>(ptr);
  
   if(ptr1!=nullptr)
   {
     cout<<"Object is  of Gmail"<< endl;
   }
  
  if(p!=nullptr)
  {
   cout<<"Object is of  GoogleDrive"<<endl;
  }
}  
 
int main()
{
  Gmail a1;
 
  GoogleDrive a2;

  findproduct(&a1);
  findproduct(&a2);
  return 0;
}


 
