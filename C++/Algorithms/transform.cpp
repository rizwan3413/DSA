#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

void print(int a)
{
    cout << a << " ";
}

int main()
{
    string str1 = "This is My India";
    
    vector<int> vect = {1,2,4,5,6,1,0,1,-1,-2,-3};

    for_each(vect.begin(),vect.end(),print);
    
    cout << endl << endl;
    
    int var = 10;
    
    //transform takes four arguments first iterator,second iterator,first iterator,Lamda or a function
    
    transform(vect.begin(),vect.end(),vect.begin(),[&](int a){return a+=var;}); 
    
    transform(str1.begin(),str1.end(),str1.begin(),::toupper); 
    
    
    for_each(vect.begin(),vect.end(),print);
    
    cout << endl << endl;
    
    cout << str1 << endl;
 	
	return 0;
}