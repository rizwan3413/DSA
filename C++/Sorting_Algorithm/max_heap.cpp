#include <iostream>
using namespace std;

#include<iostream>
using namespace std;

class MaxHeap
{
    public:
    
    int size;
    int max_size;
    int *arr;
    
    MaxHeap(int var):size(0),max_size(var),arr(new int[max_size]){}
    
    int left(int i)
    {
        return 2*i+1;
    }
    
    int right(int i)
    {
        return 2*i+2;
    }
    int parent(int i)
    {
        return floor((i-1)/2);
    }
    
    void swap(int *a,int*b)
    {
        int temp =0;
        
        temp =*a;
        *a= *b;
        *b =temp;
    }
    
    void heapify(int idx)
    {
        int largest = idx;
        int l = left(idx);
        int r = right(idx);
        
        if(arr[r]>arr[idx] && r<size)
        {
            largest = r;
        }
        
        if(arr[l]>arr[idx] && r<size)
        {
            largest = l;
        }
        if(largest!=idx)
        {
            swap(&arr[largest],&idx);
        }
    } 
    void insert(int num) 
    {
        if(size==max_size)
        {
            cout<<"Heap is already full"<< endl;
        }
        size++;
        
        arr[size-1] = num;
        int i = size-1;
    
        while(i!=0 && arr[parent(i)]<arr[i])
        {
            swap(arr[parent(i)],arr[i]);
            
            i = parent(i);
        }
    }
};

int main()
{
    MinHeap obj1(10);
    cout << obj1.max_size << endl;
    
    if(obj1.arr==nullptr)
    {
        cout << "NULL" << endl;
    }
    
    cout<<"Implementing Heap insert"<< endl;
    
    for()
    return 0;
    
}