#include<iostream>
#include<thread>
using namespace std;

int main()
{
	thread t1([]()
	{
		int sum=0;
		for(int i=1;i<101;i++)
		{
			sum+=i;
		}
		cout<<"The Value of Sum: " <<" "<<sum<<endl;

	});
	cout<<"Main thread"<<endl;
	t1.join();	
	return 0;
}


	
