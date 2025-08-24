#include<iostream>
using namespace std;

void swap(int *a,int *b)
{

    int temp =0;
    temp =*a;
    *a =*b;
    *b =temp;
}

int partition(int a[],int start_idx, int end_idx)
{
    int i = start_idx -1;
    
    int pivot = a[end_idx];

    for(int j=start_idx;j<=end_idx-1;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[end_idx]);
    return (i+1);
}

void QuickSort(int a[],int start_idx,int end_idx)
{
    if(start_idx<end_idx)
    {
    
        int pi = partition(a,start_idx,end_idx);
    
        QuickSort(a,start_idx,pi-1);
        QuickSort(a,pi+1,end_idx);
    }
    
}

void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    int arr[] = {7,8,9,12,1,2,3,5};
    
    int size = sizeof(arr)/sizeof(arr[0]);

    QuickSort(arr,0,size-1);
    
    print(arr,size);

    return 0;
}
