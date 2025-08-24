#include<iostream>
#include<thread>
using namespace std;

class test
{
public:

/*	void operator()()
	{	
		for(int i=0;i<5;i++)
       		{
                	cout<<"Function"<<endl;
                	this_thread::sleep_for(chrono::seconds(1));
        	}
	}
*/

void fun()
{
	for(int i=0;i<5;i++)
	{
		cout<<"Function"<<endl;
		this_thread::sleep_for(chrono::seconds(1));
	}
}
};

int main()
{
	test a1;
//	a1();
	thread t1(&test::fun,&a1);
	for(int i=0;i<5;i++)
	{
		cout<<"Thread main"<<endl;
		this_thread::sleep_for(chrono::seconds(1));
	}

	t1.join();

	return 0;
}
	


