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
    
    vector<int> vect1(11);
    
    auto itr = copy(vect.begin(),vect.begin()+11,vect1.begin());// returns an iterator to the last element in the range after copy  
    
    //It is wise to use remove and erase together as erase can take the iterator above it and untill the end 
    
    for_each(vect1.begin(),vect1.end(),print);
    
	if(itr == vect1.end())
	cout << "\nElements have succesfully copied" << endl;
	
	return 0;
}