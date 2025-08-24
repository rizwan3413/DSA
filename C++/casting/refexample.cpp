#include<iostream>
#include<utility>
#include<vector>
#include<string>
#include<functional>

using namespace std;

class Test
{
   public:   
    void getUpdate(string def)
	{
 	   def = "Rizwan";          
	   cout<<"Name is " << def << endl;
	}
};

int main()
{
    Test t1;
    string var ="LOTUS";
    //std::vector<string> riz;
    cout<<"The Value of Var is " << var << endl;
    t1.getUpdate(std::ref(var));

    //riz.push_back(std::move(var));
    cout<<"The Value of Var is " << var << endl;

    return 0;
}
