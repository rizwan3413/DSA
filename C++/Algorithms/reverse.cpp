#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void print(int a)
{
    cout << a << " ";
}

int main()
{
    vector<int> vect = {1,2,4,5,6,1,0,1,-1,-2,-3};

    for_each(vect.begin(),vect.end(),print);
    
    cout << endl;
    
    reverse(vect.begin(),vect.end());  
    
    //It is wise to use remove and erase together as erase can take the iterator above it and untill the end 
    
    for_each(vect.begin(),vect.end(),print);
	
	return 0;
}