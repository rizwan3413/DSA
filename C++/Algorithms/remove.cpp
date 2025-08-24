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
    
    auto itr = remove(vect.begin(),vect.end(),1);// returns an iterator to an element just after the last element not removed 
    
    cout << *itr << endl;
    
    //It is wise to use remove and erase together as erase can take the iterator above it and untill the end 
    
    vect.erase(itr,vect.end());
    
    for_each(vect.begin(),vect.end(),print);
    
    auto itr1 = remove(vect.begin(),vect.end(),1);
 
	// If the element is already removed the iterator will point to the end
    if(itr1 == vect.end())
    cout<< "\nElement already removed" << endl;
	
	return 0;
}