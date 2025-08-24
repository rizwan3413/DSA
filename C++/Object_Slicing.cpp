
/*Inheritance

Single-level
Multi-level
Multiple -Daimond Problem

Object Slicing*/

#include <iostream>
#include <vector>
using namespace std;

class Base
{
public:
	int x;

	int y;

	Base() :x(0), y(0) {}
	Base(int X,int Y) :x(X), y(Y) {}

	virtual void print() { 
		cout << " x is :" << x << endl;
		cout << " y is :" << y << endl;
	}

};

class Derived : public Base
{
public:
	int u;
	int v;

	Derived() :u(0),v(0) {}
	Derived(int X, int Y) :u(X), v(Y) {}

	void print() {
		Base::print();
		cout << " u is :" << u << endl;
		cout << " v is :" << v << endl;
	}

};
int main() {
	cout << "Size of Base " << sizeof(Base) << endl;
	cout << "Size of Derived " << sizeof(Derived) << endl;

	Derived d(24,25);
	
	Base *ptr = &d;
	ptr->print();
	return 0;
}