
#include<iostream>
using namespace std;

class Telematics
{

    public:
    
    int x;

    void set(int y)
    {
	this->x = y;
	cout<< "The value of x is : " << this->x << endl;
    }

 };

class iData
{

    public:
    float z;
    
    void set(float w)
    {

	this->z = w;
	cout<<" The Value of z is : " << this->z << endl;
    }
};

int main()
{

    Telematics t1; 
    t1.set(20);
    iData a1;
    a1.set(20.1245);
    
    Telematics *ptr = reinterpret_cast<Telematics *>(&a1);
    iData *ptr1 = reinterpret_cast<iData *>(&t1);
    cout<<"The Value of ptr is : " << ptr->x << endl;
    cout<< " The Value of pt1 is : " << ptr1->z << endl;
    return 0;
}

    


	
    
