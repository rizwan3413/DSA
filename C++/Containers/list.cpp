#include<iostream>
#include<vector>
#include<list>
using namespace std;

int main()
{
 std::vector<int> a = {1,2,34,5,6,7,8,9};

 std::list<int> b = {1,3,4,5,9,7};

 cout <<" Started printing Address of Vector "<< endl;

 for(const auto &e:a)
 {
   cout << &e << endl;
 }

 cout <<" Started printing Address of List "<< endl;

 for(const auto &e1 :b)
{

 cout << &e1 << endl;
}

cout<< *(a.data()+6)<< endl;

//cout << a.at(8) << endl;

//cout<< a.at(0) << endl;

//cout << b.at(0) << endl;

return 0;

}

