
#include<iostream>
using namespace std;

class Telematic                                    

{
     public:
     string x;
   virtual  void set(string y)
     {
	this->x = y;
	cout<<" The Value of x is : " << this->x << endl;
     }

};

class Hr :public Telematic
{

    public:
    
    int z;
    void set(int c)
    {
	this->z = c;
	
	cout<<" The Value of z is : " << this->z << endl;
     }
};

class Ble :public Telematic
{

    public:

    float a;
    void set(float d)
    {
        this->a = d;

        cout<<" The Value of z is : " << this->a << endl;
     }
};  

int main()
{
   Telematic *ptr1 = new Telematic;
   ptr1->set("Chess");
   
   Ble *ptr = dynamic_cast<Ble *>(ptr1);
   if(ptr != nullptr)
   cout<< "Its a " << ptr->x << " Game " << endl;
   
    else
    cout<< " It is NULL"<< endl;

   return 0;
}
   
  










  
    

