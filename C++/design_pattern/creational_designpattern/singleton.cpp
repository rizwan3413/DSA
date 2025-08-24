#include<iostream>
using namespace std;

class test
{
};

class singleton
{

private:

	static singleton *ptr;
	singleton(){}
	singleton(const singleton &chr){}
public:
  	 static singleton* get_instance()
	{
		if(ptr==nullptr)
		{
			ptr = new singleton;//block of memory of 4 bytes will be allocated
			
			return ptr;
		}
		else
		return ptr;
	}

	static void reset_instance()
	{
		cout<<"Reset Function is called"<<endl;
		if(ptr!=nullptr)
		{
		//	ptr = nullptr;
			delete ptr;
			ptr = nullptr;
		}	
	}
	void test(void)
	{
		cout<<"I'm a test function"<<endl;
	}

};

singleton* singleton :: ptr = nullptr;
int main()
{
	test a1,a2;
	singleton *var = singleton::get_instance();
	var->test();
	singleton* var2 = singleton::get_instance();
	var2->test();
	cout<<var<<" "<<var2<<" "<<sizeof(singleton)<<" "<<sizeof(test)<<&a1<<" "<<&a2<<endl;
	//singleton var3 = *var;
	//var3.test();
	//cout<<var<<" " <<var2<<" "<<&var3<<endl;
	singleton::reset_instance();
	return 0;
}

		
		


