
#include <iostream>
using namespace std;

int BinarySearch(int a[],int start_idx,int end_idx,int n)
{
    int mid;
    
    while(start_idx <= end_idx)
    {
        mid = (start_idx+end_idx)/2;
        
        if(n == a[mid])
        return mid;
        
        if(n > a[mid])
        {
            start_idx = mid+1;
        }
        
        if(n < a[mid])
        {
            end_idx = mid-1;
        }
        
    }
    return -1;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8};

    int size = sizeof(arr)/sizeof(arr[0]);

    int val = BinarySearch(arr,0,size-1,8);
    
    (val == -1)?cout<<"The Element does not exist" :cout<<"The Element is at " << " " <<val<< " "  << "poisition" << endl;
    
    return 0;
}


With Recursion :
===============

#include<iostream>
using namespace std;

int BinarySearch(int arr[],int start_idx,int end_idx,int n)
{
    if(start_idx<=end_idx)
    {
        int mid = (start_idx+end_idx)/2;
        
        
        if(arr[mid]== n)
        {
            return mid;
        }
         
        if(n < arr[mid])
        {
            BinarySearch(arr,start_idx,mid-1,n);
        }
        
        if(n > arr[mid])
        {
            BinarySearch(arr,mid+1,end_idx,n);    
        }
        
        
    }
   
   else 
   return -1;
}

int main()
{
    int arr[] = {1,5,8,9,17,25,32,46};
    
    int size = sizeof(arr)/sizeof(arr[0]);
    
    int result = BinarySearch(arr,0,size-1,46);
    
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result; 
    return 0;
}