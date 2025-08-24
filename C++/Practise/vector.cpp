#include<iostream>
using namespace std;

template<typename T>
class Vector
{


 private:
 
 T *arr;

 size_t max_size;

 size_t current_size;

 public:

   Vector():arr(nullptr),max_size(50),current_size(0) 
 {
    cout<< "Constructor Call " << endl;

    arr = new T[max_size];
 }  

 ~Vector()

 {
	delete [] arr;
 }

 T operator [] (int index)
 {
   if(index>=current_size)
   {
     cout<<"Index out of bound" << endl;
     return -1;
   }
  
   return arr[index];
 }

 void push_back(T a)

 {
       if(current_size >= max_size)
	{
		max_size*=4;

		T *temp = new T[max_size];
                
  		for(int i = 0; i<current_size;i++)
		{
			temp[i] = arr[i];
		}
	
		arr = temp;
	}
	
	arr[current_size] = a;
  
        current_size++;
 } 

 size_t size()
 {

   return current_size;
 }

 T * begin()
 {

   return arr;
 }
 
 void pop_back()
 {
   current_size--;
 }

template<typename T>
 class Iterator
{
  public:
    
  T *ptr;

 Iterator():ptr(nullptr)
 {
   ptr = new T;
   

  // Iterator &obj = ptr;

 }
 
 ~Iterator()
{
  delete ptr;
}

Iterator& operator = (T* a)
{
  ptr = a;

  return *this;
}
 
T operator *()
{
   return 
}
};

};
 
int main()

{

  Vector<int> obj;

  /*obj.push_back(15);
  obj.push_back(10);
  obj.push_back(20);
  obj.push_back(30);
  obj.push_back(40);
  obj.push_back(50);
  obj.push_back(60);
  obj.push_back(70);
  obj.push_back(80);
*/
 for (int i = 0; i<100; i++)
 {

   obj.push_back(i);
 }
  for(int i = 0;i<obj.size(); i++)
 {
     cout<< obj[i] << " " << endl;
 }

 cout <<" =======================" << endl;

 cout << obj.size() << endl;
 
 Vector::Iterator<int> itr;

 for( itr = obj.begin(); itr<obj.size();itr++)

 {
    cout<< *itr << endl;
 }
    
  return 0;
}

 
ut << obj[100000000000] << end

