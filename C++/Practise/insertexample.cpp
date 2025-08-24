#include<iostream>
using namespace std;

int main()
{

 int size,position,new_element,a[size+1];

 cout<<"Enter the size of an array"<< endl;

 cin>>size;

 cout<<"Enter the Elements"<<endl;
 
 for(int i = 0;i<size;i++)
 {
   cin>>a[i];
 }

 cout<<"Enter the position the elements has to be insered"<< endl;
 
 cin>>position;

 cout<<"Enter the new Element"<<endl;
 cin>>new_element;
 
  a[position-1] = new_element;
 
 for(int i = size; i>position-1; i--)
 {

   a[i] = a[i-1];
 }
  
cout<<"Array content after insertion"<<endl;
 for(int i = 0; i<=size;i++)
 {
  
   cout<<a[i]<< " " << endl;
 }

return 0;

}


 
    
