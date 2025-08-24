#include<iostream>
using namespace std;

void swap(int *a,int*b)
{
    int temp =0;
    temp = *a;
    *a =*b;
    *b =temp;
}

void SelectionSort(int a[],int n)
{
    int min=0;

    for(int i=0;i<n;i++)
    {
        min = i;

        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min = j;
            }
        }
        
      swap(&a[i],&a[min]);
    }
}

int main()
{
    int arr[] = {7,8,9,1,2,3,5};
    
    int size = sizeof(arr)/sizeof(arr[0]);
    
    SelectionSort(arr,size-1);
    
    for(int i=0;i<size-1;i++)
    {
        cout<< arr[i]<< " ";
    }
    
    cout<<"\n";

    return 0;
}


