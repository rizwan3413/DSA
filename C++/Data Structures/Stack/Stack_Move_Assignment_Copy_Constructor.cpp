#include<iostream>
using namespace std;

template<typename T>
class Stack 
{
    
    T *arr;
    
    size_t maxSize;
    
    size_t size;
    
    int top;
    
    public:
    
    Stack():arr(nullptr),maxSize(0),size(0),top(-1){}
    
    Stack(size_t maxSize):arr(nullptr),maxSize(maxSize),size(0),top(-1)
    {
         arr = new T[maxSize];
    }
    
        
    Stack & operator = (const Stack &rhs)
    {
        if(this!= &rhs)//S1 <-S2 // S1 <- S3
        {
            delete [] arr;
            arr = new T[rhs.maxSize];
            maxSize = rhs.maxSize;
            size = rhs.size;
            top = rhs.top;
            
            for(int i = 0;i < size;i++)
            {
                arr[i] = rhs.arr[i];
            }
        }
        return *this;
    }
    
    Stack(const Stack &rhs):arr(new T[rhs.maxSize]),maxSize(rhs.maxSize),size(rhs.size),top(rhs.top)
    {
        for(int i = 0;i < size;i++)
        {
            arr[i] = rhs.arr[i];
        }
    }
    //Move Assignment Operator
    Stack & operator = (Stack &&rhs)
    {
        if(this!= &rhs)//S1 <-S2 // S1 <- S3
        {
            delete [] arr;
            size = rhs.size;
            maxSize = rhs.maxSize;
            top = rhs.top;
            
            arr = rhs.arr;
            
            rhs.maxSize = 0;
            rhs.size = 0;
            rhs.top = -1;
            rhs.arr = nullptr;    
                
        }
        return *this;

    }
    
    //Move Constructor
    Stack(Stack &&rhs):arr(nullptr),maxSize(rhs.maxSize),size(rhs.size),top(rhs.top)
    {
        rhs.maxSize = 0;
        rhs.size = 0;
        rhs.top = -1;
        arr = rhs.arr;
        rhs.arr = nullptr;
    }
    
    ~Stack()
    {
        delete [] arr;
    }
    
    void push(T data)//O(1)
    {
       if(size <= maxSize)
       {
           arr[++top] = data;
           size++;
       }
       else
        cout << "Stack Overflow has occured" << endl;
    }
    
    void pop()//O(1)
    {
        if(size == 0)
        {
            cout << "Stack is already empty" << endl;
        }
        else 
        {
            size--;
            top--;
        }
    }
    
    int getTop()
    {
        return top;
    }
    size_t getSize()
    {
        return size;
    }
    
    size_t maximumSize()
    {
        return maxSize;
    }
    
    bool isEmpty()
    {
        return (size == 0); 
    }
    
    void print()
    {
        for(int i = top;i>=0;i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
};

int main()
{
    Stack<int> S1(5);
    
    S1.push(1);
    S1.push(2);
    S1.push(3);
    S1.push(4);
    S1.push(5);
    S1.push(6);
    
    //Stack<int> S2(std::move(S1));
    
    Stack<int> S2;
    
    S2 = std::move(S1);
    
    S2.print();
    
    S1.print();
    
    /*S1.pop();
    S1.pop();
    S1.pop();
    S1.pop();
    S1.pop();
    S1.pop();
    
    S1.pop();
    
    if(S1.isEmpty()) cout << "Stack is empty" << endl;
    
    S1.print();
    */
    return 0;
}