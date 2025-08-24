#include<iostream>
using namespace std;


class Test 
{
    public:
    
    int *ptr;
    
    int size;
    
    Test():ptr(nullptr),size(0){}
    
    Test(int *p,int y)
    {
        size = y;
        
        if(size!=0)
        {
            ptr = new int[size];
            
            for(int i = 0;i<size;i++)
            {
                ptr[i] = p[i];
            }
        }
    }
    
    int& operator [] (int index)
    {
        if(index >= size)
        {
            cout << "Out of Bound ,exiting" << endl;
            exit(0);
        }
        
        return ptr[index];
    }
    
    void print()
    {   
        for(int i=0;i<size;i++)
        {
            cout << ptr[i] << " ";
        }
        cout << "\n";
    }
    
};

int main()
{
    int arr[] = {1,2,3,4,5,7};
    
    Test a1(arr,6);
    
    a1.print();
    
    for(int i=0;i<6;i++)
    {
    
        a1[i] = i*10;
    }
    
    a1.print();

    return 0;    
}