#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Observer
{


public:
	virtual void callOnEvent(int,int)=0;//()- Function operator

};


class FirstObserver:public Observer

{
public:
	void callOnEvent(int a,int b)
	{
		cout<<"The Value of a is: "<< " " <<a<<endl;
		cout<<"The Value of b is: "<< " "<<b<<endl;

	}
};

class SecondObserver: public Observer

{
public:
	void callOnEvent(int a,int b)
	{
		cout<<"The Value of Addition is : " << a+b<<endl;
		cout<<"The Value of Subtraction is : "<< a-b<<endl;
	}
		
};

class Registry

{

private:

	std::vector<Observer*> list_of_observer;

public:

	void register_Observer(Observer *ptr)
	{
		cout<<"Adding Observer"<<endl;

		list_of_observer.push_back(ptr);
		
		cout<<"The Contents of the Vector are :"<< endl;

		for(Observer* var:list_of_observer)
		{	
	
			cout<<" " << var; 
		} 
		cout<<endl;

	}

	void unregister_Observer(Observer *ptr)
	{
		
	    cout<<"Delete Observer"<<endl;
	   
	    
	    auto itr = find(list_of_observer.begin(),list_of_observer.end(),ptr);
	    
	    if(itr != list_of_observer.end())
		{
			list_of_observer.erase(itr);
		}
		
	}

	void notify_Observer()
	{
		for(auto itr=list_of_observer.begin();itr<list_of_observer.end();itr++)
			{
				(*itr)->callOnEvent(5,10);
			}
	}	
};

int main ()

{
	
	FirstObserver a1;
	SecondObserver a2;
	Registry a3;
	a3.register_Observer(&a1);
	a3.register_Observer(&a2);
	a3.notify_Observer();
	return 0;
}

	    
            
	
		

