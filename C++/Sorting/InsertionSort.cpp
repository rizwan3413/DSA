#include<iostream>
using namespace std;

void InsertionSort(int a[],int n)
{
    int temp,j;

    for(int i=1;i<n;i++)
    {
        temp = a[i];
        
        j = i-1;
    
        while(j>=0&&a[j]>temp)
        {
            a[j+1] =a[j];
            j--;
            
        }
        a[j+1] = temp;
    }
}

int main()
{
    int arr[] = {7,8,9,1,2,3,5};

    int size = sizeof(arr)/sizeof(arr[0]);
    
    InsertionSort(arr,size-1);
    
    for(int i=0;i<size-1;i++)
    {
        cout<< arr[i] << " ";
    }

    cout<<"\n";

    return 0;
}

