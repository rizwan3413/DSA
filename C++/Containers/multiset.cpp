#include<iostream>
#include<set>
#include<string>
#include<functional>
using namespace std;

class Person
{
 public:
 float age;
 string name;

 bool operator < (const Person&rhs)const{return age<rhs.age;}
};

int main()
{

 //multiset<int> Set = {1,2,3,4,5,6,1,2,5,6,7,8,9,9};

 multiset<Person> Set = {{25,"Rizwan"},{27,"Ahmed"},{28,"Mujahid"},{25,"Rizwan"}};

 Set.insert({30,"Jawwad"});

 for(auto itr:Set)
 {
   cout << itr.age << " "<< itr.name<< endl;

 }

 cout << "\n";
 return 0;
}

