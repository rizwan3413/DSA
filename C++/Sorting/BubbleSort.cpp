#include<iostream>
using namespace std;


void swap(int *a,int *b)
{

    int temp =0;
    temp =*a;
    *a =*b;
    *b =temp;
}
    
void BubbleSort(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j =0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(&a[j],&a[j+1]);
            }
        }
    }
}
  
int main()

{
    int arr[] = {7,8,9,1,2,3,5};
    
    int size = sizeof(arr)/sizeof(arr[0]);
    
    BubbleSort(arr,size);
    
    for(int i=0;i<size-1;i++)
    {
        cout<< arr[i] << " ";
    }
   
    cout<<"\n";
 
    return 0;
}

