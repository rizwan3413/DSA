Linear Search:
=============

#include<iostream>
using namespace std;

int LinearSearch(int arr[],int n,int x)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
        return i;
    
    }
    
    return -1;
}

int main()
{
    int a[] ={10,15,11,5,15,25};
    
    int size = sizeof(a)/sizeof(a[0]);
    
    int result = LinearSearch(a,size,25);
    
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result; 
    return 0; 
  
}