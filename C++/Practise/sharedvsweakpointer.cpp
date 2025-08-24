#include<iostream>
#include<string>
#include<memory>
using namespace std;

class Child;

class Parent
{
 private:

 string name;

 weak_ptr<Child> child;

 public:

 Parent(string Parentname):name(Parentname)
 {
   cout << "Parent---->  " << name << "Constructor call..."<< endl;
 }

 ~Parent()
 {

   cout<< " Parent---->  "<< name << " Destructor call ..." << endl;
 }
 
 void setChild(shared_ptr<Child> child)
 {
   this->child = child;
 }

};

class Child
{
 private:

 string name;

 shared_ptr<Parent> Dad;
 shared_ptr<Parent> Mom;
 
 public:
 Child(string name,shared_ptr<Parent>father,shared_ptr<Parent>mother)
 {
  name = name;
  
  Dad = father;
  Mom = mother;

  cout<< "Child---->  "<< name << "Constructor Call ... " << endl;
 }

 ~Child()
 {
   cout << "Child---->" << name << "Destructor Call ..." << endl;
 }

};

int main()
{

 shared_ptr<Parent> ptr(new Parent("Dad"));
 shared_ptr<Parent> ptr2(new Parent("Mom"));
 
 shared_ptr<Child> ptr3(new Child("Child",ptr,ptr2));

 ptr->setChild(ptr3);

 ptr2->setChild(ptr3);

 return 0;
}

