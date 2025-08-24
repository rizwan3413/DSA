#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main()
{
	vector<int> base;
	
	int b = 20;
	int d = 10;
	int c = 5;

	for(int i=0;i<10;i++)
	{
	
		base.push_back(i);
	}
		
	cout<<"\n The Elements of the vector are "<<endl;

	for(auto itr = base.begin();itr<base.end();itr++)
	{
		cout<< *itr <<" ";
	}
	
	 cout<<"\n The Elements of the vector are "<<endl;

	for(int a:base)//using container base for loop
	{
                cout<< a <<" ";

	}
	cout<<endl;
	
	
	cout<<"\n The Elements of the vector are "<<endl;

	for_each(base.begin(),base.end(),[&](int a) //sqaure brackets are used to capture variables outside function body also kniwn as capture class
	{cout<< b << " "<< a << " "<< endl;
	 b = 25;
	 d = 15;
	 c = 100;});
	
	cout << b << " "<< c <<" "<< d <<endl;
	auto ret = [](int a ,int b){ return a+b;};
	cout<< ret(2,3) << endl;
	
	return 0;
}












