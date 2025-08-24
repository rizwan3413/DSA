#include<iostream>
#include<string>
using namespace std;

class Cake
{

public:

	virtual void addtoping(string)=0;

};

class PineappleCake:public Cake
{

private:

	string toping;
public:

	void addtoping(string pine)
	{
	
		toping = pine;
		cout<<"Adding Toping to Pineapple Cake"<<endl;
	}
};

class ChocolateCake:public Cake
{

private:
	string toping;

public:

	void addtoping(string choc)
	{
		toping = choc;
		cout<<"Adding Toping to Chocolate Cake"<<endl;
	}
	
};


class CakeFactory
{

public:

	static Cake* CreateCake(int a)
	{
		switch(a)
		{
	
			case 1 :return new PineappleCake;
			case 2 :return new ChocolateCake;
			default:return nullptr;
		}
	}
};

int main()
{

	Cake *ptr1 = CakeFactory::CreateCake(1);
	ptr1->addtoping(string ("pine"));
	
	Cake *ptr2 =  CakeFactory::CreateCake(2);
        ptr2->addtoping(string ("chocolate"));
	
	return 0;
}

	
