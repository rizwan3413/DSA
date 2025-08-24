#include<iostream>
#include<set>
#include<functional>
using namespace std;

class Person
{
 public:
 float age;
 string name;

 bool operator <(const Person& obj) const { return age<obj.age;}

 bool operator >(const Person& obj) const { return age>obj.age;}
};


int main()
{
  set<Person,std::greater<Person>> Set = {{25,"Rizwan"},{26,"Murtuza"},{27,"Maaz"}};

  //set<int> Set={1,2,3,4,5,1,2,4,5,7};

  Set.insert({28,"Yasir"});


  for(auto set:Set)
  {
    cout<< set.age << " "<< set.name << endl;
  }
  cout<<"\n";

return 0;
}


