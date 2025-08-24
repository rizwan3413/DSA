#include <iostream>
using namespace std;
void Mergefun(int arr[],int strt_idx,int mid_idx,int end_idx)
{
  int size_arr1 = (mid_idx)-strt_idx;
  int size_a1 =   end_idx - mid;
  int i=0;
  int j=0;
  while(i<size_arr1)
  {
    int arr1[i] = arr[strt_idx+i];
	i++;
  }
	
 while(j<size_a1)
  {
    int arr1[j] = arr[mid_idx+j];
	j++;
  }
	  
  int final_idx=0;
  while(arr1_idx<size_arr1 && a1_idx<size_a1)
  {
    if(arr1[arr1_idx]>=a1[a1_idx]) // 1>=11 false
	{
	  array[final_idx] = a1[a1_idx];
	  a1_idx++;
	}
	else 
	{
	 array[final_idx] = arr1[arr1_idx]; // 1
	  arr1_idx++;
	}
	final_idx++;
  }
  
 while(arr1_idx<size_arr1)
 {
   array[final_idx] = arr1[arr1_idx];
   final_idx++;
   arr1_idx++;
 }   

 while(a1_idx<size_arr1)
 {
   array[final_idx] = a1[a1_idx];
   final_idx++;
   a1_idx++;
 }   
	
 for(int i=0;i<final_idx;i++)
 {
  cout << array[i] << " ";
 }
 cout << "\n";
 }
	 
  void MergeSort(int a[],int strt_idx,int end_idx)
  {
    if(strt_idx>=end_idx)
	return;
	
     int mid_idx = strt_idx+end_idx/2;
	 MergeSort(a,strt_idx,mid-1);//(a,0,1);
	 MergeSort(a,mid,end_idx);
	 Mergefun(a,strt_idx,mid_idx,end_idx);
  }
	
int main()
{
 int ar[] = { 1,5,7,11,0,15,25,4,2,24,11};
 
 int size = sizeof(ar)/sizeof(ar[0]);
 
  for(int i=0;i<size;i++)
 {
  cout << ar[i] << " ";
 }
 cout << "\n";
 }
 MergeSort(ar,0,size-1);
 return 0;
}