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
    vector<int> vect = {1,2,4,5,6,1,0,1,-1,-3};

    for_each(vect.begin(),vect.end(),print);
    
    cout << endl;
    
    auto itr = count_if(vect.begin(),vect.end(),[](int i){ return (i%2 == 0) &&(i!=0);});// returns an iterator to an element just after the last element not removed 
    
    cout << "No of even number in the vector is : " << itr << endl;
    
    //It is wise to use remove and erase together as erase can take the iterator above it and untill the end 
    
    if(itr == 0)
    cout<< "\nElements satisfying the condition are not present " << endl;
	
	return 0;
}