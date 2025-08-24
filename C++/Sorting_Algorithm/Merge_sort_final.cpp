#include <iostream>
using namespace std;

int size=0;

void Mergefun(int arr[],int strt_idx,int mid_idx,int end_idx)
{
    int size_arr1 =   mid_idx+1 - strt_idx;
    int size_arr2 =   end_idx - mid_idx;
    
    //size = size_arr1+size_arr2;
    int i=0;
    int j=0;
    int arr1[size_arr1];

    while(i<size_arr1)
    {
        arr1[i] = arr[strt_idx+i];
	    i++;
    }
    
	int arr2[size_arr2];
	
    while(j<size_arr2)
    {
        arr2[j] = arr[mid_idx+1+j];
	    j++;
    }
	  i = 0;j=0;
    int final_idx=strt_idx;
    
    while(i<size_arr1 && j<size_arr2)
    {
        if(arr1[i]>=arr2[j])
	    {
	        arr[final_idx] = arr2[j];
	        j++;
	    }
	    else 
	    {
	        arr[final_idx] = arr1[i];
	        i++;
	    }
            final_idx++;
    }
  
    while(i<size_arr1)
    {
        arr[final_idx] = arr1[i];
        final_idx++;
        i++;
    }   

    while(j<size_arr2)
    {
        arr[final_idx] = arr2[j];
        final_idx++;
        j++;
    }   
 
 for(int i=0;i<size;i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
   
}
	 
  void MergeSort(int a[],int strt_idx,int end_idx)
  {
    if(strt_idx>=end_idx)
	return;
	
     int mid_idx = (strt_idx+end_idx)/2;
	 MergeSort(a,strt_idx,mid_idx);
	 MergeSort(a,mid_idx+1,end_idx);
	 Mergefun(a,strt_idx,mid_idx,end_idx);
  }
	
int main()
{
 int ar[] = { 1,5,7,13,0,15,25,4,2,24,11};
 
  size = sizeof(ar)/sizeof(ar[0]);
 
  for(int i=0;i<size;i++)
 {
  cout << ar[i] << " ";
 }
 cout << "\n";
 
 MergeSort(ar,0,size-1);
 
 	 
 return 0;
}
