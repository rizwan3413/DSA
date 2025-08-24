// C++ program to implement BubbleSort operation in an unsorted array

#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp =0;
    
    temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
              swap(&a[j],&a[j+1]);
            }
        }
    }
}

/* Driver code */
int main()
{
    int arr[6] = { 12, 16, 20, 40, 50, 70 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<< "\nBefore Sorting";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    //After BubbleSort
    BubbleSort(arr, n);

    cout << "\nAfter Sorting : ";
    for (int i = 0; i < n; i++)
        cout << arr[i]<< " ";

    return 0;
}


