#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

/*Lambda Expression 

[] -Capture Clause

()-Input Parameters

{}- Body of the Lamda
 
*/

bool isdiv3 (int a)
{
 return a%3 == 0;
}

int main()
{
 std::vector<int> v = {1,5,9,11,1,25,1};
 
 int c = count(v.begin(),v.end(),1);

 int b = count_if(v.begin(),v.end(),[](int ch){return ch%5==0; });
 
 int d = count_if(v.begin(),v.end(),isdiv3);
 
 for_each(v.begin(),v.end(),[](int a){cout << a << " ";});

 cout << "\nCount of 1's in Vector is " << c << endl;
 cout << "Count of Number of Elements Divisibile by 5 " << b << endl;
 cout << "Count of Number of Elements Divisible by 3 " << d << endl;

 int var = 15;
 int sum = 0;

 for_each(v.begin(),v.end(),[&](int a){sum+=(var+a);});

 cout << sum << endl;
 
 std::function<void ()> printvector = [&](){for(auto vec:v){cout<<vec << " ";} cout << "\n";};

 printvector();

 transform(v.begin(),v.end(),v.begin(),[&](int c){ return c+=var;});

 printvector();

 replace(v.begin(),v.end(),16,500);

 printvector();
 
 std::vector<int>::iterator itr = remove(v.begin(),v.end(),500);
  for(auto it =v.begin(); it!=itr;it++)
  {
    cout<<*it<<" ";
  }


 cout<<"\n";

//Range based For loop

 for(auto vec1:v){cout<< vec1 << " ";}cout<<"\n";

 std::vector<int>::iterator itr1 = remove_if(v.begin(),v.end(),isdiv3);
 
 for(auto it =v.begin(); it!=itr1;it++)
  {
    cout<<*it<<" ";
  }

 cout << "\n";

 return 0;
}



