#include<iostream>
using namespace std;

template<typename T>
class Stack
{
  T * arr;
  
  size_t maxsize;
  
  size_t size;
  
  int top;
  
  Stack(size_t maxSize):arr(nullptr),maxSize(maxSize),size(0),top(-1)
  {
	arr = new T[maxSize];
  }
  
  ~Stack()
  {
	  delete [] arr;
  }
    
  void push(T data)
  {  
	  if ( size <= maxSize)
	  {
		  arr[++top] = data;
		  size++;
	  }
	  else
	  {
		  cout << "Stack overflow has occured" << endl;
	  }
  }
  
  void pop()
  {
	  if ( size == 0)
	  {
		  cout << "Stack is already empty << endl;
	  }
	  else
	  {
		  size--;
		  top--;
	  }
  }
  
  size_t getSize()
  {
	  return size;
  }
  
  bool isEmpty()
  {
	  return (size == 0)
  }
  
  void print()
  {
	  for(int i = 0; i < size ; i++)
	  {
		  cout << arr[i] << " ";
	  }
  }
  
 
int main()
{
  Stack<int> S1(5);
    
    S1.push(1);
    S1.push(2);
    S1.push(3);
    S1.push(4);
    S1.push(5);
    S1.push(6);
    
    S1.print();
    
    S1.pop();
    S1.pop();
    S1.pop();
    S1.pop();
    S1.pop();
    S1.pop();
    
    S1.pop();
    
    if(S1.isEmpty()) cout << "Stack is empty" << endl;
    
    S1.print();
    
    return 0;
}