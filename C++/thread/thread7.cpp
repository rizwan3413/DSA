#include<iostream>
#include<thread>
#include<future>
using namespace std;


int fib(int a)// && R value is something whose address cannot be shown
{
	int a1=1;
	int a2 =1;

	if(a==1||a==2)
	return 1;

	else
	{
		cout<<"In fibonacci\n";
		for(int i=3;i<=a;i++)
		{
			int t =a1;
			a1 =a2;
			a2 = a2+t;
			
		}
	
	}

	return a2;
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
	std::packaged_task<int (int)> riz(fib);// package_task is a template class it takes function prototype , we created a variable named riz  and passed the function fib inside it 

	std::future<int> var = riz.get_future();

	thread t1(std::move(riz),20);//mov(a1) -> USe of move is a way to pass a value inside the function ( It converts lvalue to Rvalue then we use move)
	cout<<"Main Thread Execution Started"<<endl;
	
	for(int i=0;i<50;i++)
        {
                cout<<"Thread main"<<endl;
              //  this_thread::sleep_for(chrono::seconds(1));
        }
	
	cout<<"The Value inside Future object is :"<<var.get()<<endl;
	
	t1.join();
	return 0;
}

