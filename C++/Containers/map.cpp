#include<iostream>
#include<map>
#include<string>
using namespace std;

class Person
{
 public:
 float  age;
 string name;
 Person(){}
 Person(float Age,string Name):age(Age),name(Name){}
 void personInfo() const
 {
  cout<< name << " " << age << endl;
 }
// bool operator < (const Person &rhs) const { return age<rhs.age;}
};

class Address
{
 public:
 string country;
 string state;
 Address(){}
 Address(string Country,string State):country(Country),state(State){}
 void addressInfo() const
 {
   cout<< country << " " << state << endl;
 }
};

int main()
{
 //Person obj(28.3,"Rizwan");
// Address obj1("USA","Illinois");

 multimap<Person,Address> Map;

 //map<string ,float> Map;
/*
 Map["enginestatus"] = 0.159;
 Map["enginespeed"] = 151.159;
 Map["gearposition"] = 5;
 Map["enginehours"] = 2780.159;
*/

 Map[Person(25.3,"Rizwan")] = Address("USA","Illinois");
 
 Map[Person(25,"Sunny")] = Address("INDIA","Bangalore");
 
 Map.insert(std::make_pair(Person(29,"Murtuza"),Address("USA","Illinois")));

 Map.insert(pair<Person,Address>(Person(31,"Yasir"),Address("USA","Texas")));

 
 for(const auto &itr:Map)
 {
   itr.first.personInfo();
   itr.second.addressInfo();
 }
 
 return 0;
}
