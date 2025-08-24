
/*Inheritance

Single-level
Multi-level
Multiple 
Hybrid Inheritance -Daimond Problem

Object Slicing*/

#include <iostream>
#include <vector>
using namespace std;

class A
{
public:
	int a;

	A() :a(0) { cout << " Base class A default Constructor Call" << endl; }
	A(int X) :a(X){
	
		cout << "Base class A Constructor Call" << endl;
		}

	void fun()
	{
		cout << " I'm base class A function" << endl;
	}
	void print() { 
		cout << " a is :" << a << endl;
	}

};

class B :virtual public A 
{
public:
	int b;

	B() :b(0){ cout << "Derived class B default Constructor Call" << endl; }
	B(int X) :b(X) { cout << "Derived class B Constructor Call" << endl; }

	void print() {
		cout << " b is :" << b << endl;
	}

};

class C:virtual public A
{
public:
	int c;

	C() :c(0){ cout << "Derived class C default Constructor Call" << endl; }
	C(int X) :c(X){ cout << "Derived class C Constructor Call" << endl; }

	void print() {
		cout << " c is :" << c << endl;
	}

};

                                                                                                              //A 
                                                                                                          //B      //C
																											  // D
class D :public B,public C
{
public:

	int d;

	D() :d(0){ cout << "Derived class D default Constructor Call" << endl; }
	D(int X) :d(X){ cout << "Derived class D Parameterized Constructor Call" << endl; }

	void print() {
		cout << " d is :" << d << endl;
		
	}

};
int main() {
	//cout << "Size of Base " << sizeof(Base) << endl;
	//cout << "Size of Derived " << sizeof(Derived) << endl;
	cout << "Size of D is " << sizeof(D) << endl;
	
	D d1(10);
	d1.a = 10;
	d1.fun();
	return 0;
}