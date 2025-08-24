#include<iostream>
#include<utility>
#include<vector>
#include<string>

using namespace std;

class Test
{
   public:   
    void getUpdate(string&& def)
	{

	   cout<<"Name is " << def << endl;
	}
};

int main()
{
    Test t1;
    string var ="LOTUS";
    std::vector<string> riz;
    cout<<"The Value of Var is " << var << endl;
    //t1.getUpdate(std::move(var));

    riz.push_back(std::move(var));
    cout<<"The Value of Var is " << var << endl;

    return 0;
}
