#include<iostream>
using namespace std;
template<typename T>

class Vector
{
  private: 
  T* arr;

  size_t max_size;

  size_t current_size;

  public:
  Vector() :arr(nullptr), max_size(50), current_size(0)
   { 
    
    cout << "Constructor Call " << endl;
    arr = new T[max_size];   
    }   

  ~Vector()
   {        
   
    delete[] arr; 
   }    
   
   T operator [] (int index)
   {        

    if (index >= current_size)
        {        
           cout << "Index out of bound" << endl;  

          return -1;  
         } 

        return arr[index]; 

   }   

  void push_back(T a)

  {    

    if (current_size >= max_size)  

      {            max_size *= 4;     
       T* temp = new T[max_size];            for (int i = 0; i < current_size; i++)            {                temp[i] = arr[i];            }            arr = temp;        }        arr[current_size] = a;        current_size++;    }    size_t size() {        return current_size;    }    T* begin() {        return arr;    }    T* end() {        return arr + curr
From Me to Everyone:  12:08 PM
hi

