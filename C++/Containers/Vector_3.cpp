#include<iostream>
#include<vector>
using namespace std;

class Result

{

public:


static int count;

Result()
{

	count++;

cout<<"i'm a defult constructor"<<endl;

	
}

~Result()

{ 
	count--;

cout<<"I'm a destructor"<<endl;

}

};

int Result:: count = 0;

int main()

{

//	vector<Result> a;
	
	Result r1,r2,r3;
	
//	a.push_back(r1);

//	a.push_back(r2);
	
//	a.push_back(r3);

//	cout<< a[0].count<<endl;
	cout<<Result::count<<endl;


	return 0;


}

