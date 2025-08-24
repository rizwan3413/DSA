#include<bits/stdc++.h>
using namespace std;

class MaxHeap
{
    public:
    
    int size;
    int max_size;
    int *arr;
    
    MaxHeap(int var):size(0),max_size(var),arr(new int[max_size]){}
    
    ~MaxHeap()
    {
        cout<< "Destructor Call" << endl;
        delete [] arr;
    }
    
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
    
    void swap(int *a,int *b)
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
        
        if(arr[l]>arr[largest]&& l<size)
        {
            largest = l;
        }
        if(largest!=idx)
        {
            swap(&arr[largest],&arr[idx]);
            heapify(largest);
        }
        
    } 
    
    int extract_max()
    {
     
        if(size==0)
        {
            //cout << " Size of Heap is zero and it cannot extract"<< endl;
            return INT_MAX;
        }
        if(size == 1)
        {
            size--;
            return arr[0];
        }
        int var =arr[0];
        swap(&arr[0],&arr[size-1]);
        size--;
        heapify(0);
        return var;
    }
    
 
    void insert(int num) 
    {
        if(size==max_size)
        {
            cout<<"Heap is already full"<< endl;
        }
        
        arr[size] = num;
        size++;
        
        int i = size-1;
    
        while(i>0 && arr[parent(i)]<arr[i])
        {
            swap(&arr[parent(i)],&arr[i]);
            
            i = parent(i);
        }
    }

    void print()
    {
        for(int i=0;i<size;i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main()
{
    MaxHeap j1(10);
    cout << j1.max_size << endl;
    
    if(j1.arr == nullptr)
    {
        cout << "NULL" << endl;
    }
  
    
    for(int i = 0; i<10;i++)
    {
        j1.insert(i);
    }
//  cout<<"Implementing Heap insert"<< endl;
    
    j1.print();
   
    cout << "\n";
   
     int Size = j1.size;
     
    for(int i=0;i<Size;i++)
    {
       cout<< j1.extract_max() << " ";
      
    }
     
    return 0;
    
}
