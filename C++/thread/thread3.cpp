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

void swap(int *a, int *b)
{
	int temp = *a;
	*a=*b;
	*b=temp;
	
	cout<<"The value of a and b after swap is :"<<*a<<" "<<*b<<endl;
	//	this_thread::sleep_for(chrono::seconds(1));
	
}
/*
void swap(int a, int b,int c)
{
        int temp = a;
        a=b;
        b=c;
	c=temp;

        cout<<"The value of a,b,c after swap is :"<<a<<" "<<b<<" "<<c<<endl;
            //    this_thread::sleep_for(chrono::seconds(1));
}
*/

};

/*
int main()
{
	test a1;
        int a=10;
	int b=15;
	

//	a1();
	thread t1(&test::swap,&a1,&a,&b);
//	thread t2(&test::swap,&a1,15,20,25);

	t1.join();
//	t2.join();

	return 0;
}

*/
