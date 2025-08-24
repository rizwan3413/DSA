#include<iostream>
#include<thread>
#include<future>
using namespace std;


int fib(int a)
{
	if(a==0||a==1)
	return 1;
	else
	{
		cout<<"In fibonacci\n";
		return fib(a-1)+fib(a-2);
	}
}

/*
	for(int i=0;i<5;i++)
	{
		cout<<"Function"<<endl;
		this_thread::sleep_for(chrono::seconds(1));
	}

}

int main()
{
	thread t1(fun);
	for(int i=0;i<5;i++)
	{
		cout<<"Thread main"<<endl;
		this_thread::sleep_for(chrono::seconds(1));
	}

	t1.join();

	return 0;
}
*/

int main()
{
	std::future <int> a1 = std::async(fib,5); 

	cout<<"Main Thread Execution Started"<<endl;
	
	for(int i=0;i<50;i++)
        {
                cout<<"Thread main"<<endl;
              //  this_thread::sleep_for(chrono::seconds(1));
        }

	cout<<"The Value of Fibonacci"<<a1.get()<<endl;

	return 0;
}

