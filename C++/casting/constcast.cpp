
#include<iostream>
#include<string>
using namespace std;

class Telematic
{
  
   public:
   
   int x = 10;//mutable //const_cast
    
    void update(int y)
    {
//      this->x = y;
      
      cout<<"The Value of x is :"<< x <<endl;
    }
 
    void button()const  // significance when kept on right side ( It means it is of type const)
    {
	
/*	(Note :Cannot modify the member variable in const function diectly 
        
         But it can be modified using const cast */
	const_cast<Telematic *>(this)->x =25;// const_cast<int>(x) = 100;

      
      cout<<"The Value of x is :"<< x <<endl;

      cout<<"I'm a Senior Embedded Engineer"<<endl;
     
    }
};

class riz
{

 public:
 
  mutable int z = 25;

 void update(int v)// This is a non-const type function
{
//	 this->z = v;
	
  //    cout<<"The Value of Z is :"<< z <<endl;

}
 void update(int n) const // Its been overloaded to be a const type function as we can only call const function with const object 
{
   this->z = n;

   cout<<"The Value of Z is :"<< z <<endl;


}
	

};


  

int main()
{
  const riz b1;
  b1.update(10);
   
  const Telematic a1;
  
  Telematic *a2 = const_cast<Telematic *>(&a1);

  a2->update(6);

  //a2->update(5);


/* First use case

 	Telematic t1;
 
	Telematic *t2;

	//t2 = const_cast<Telematic *>(&t1);
	
        //t2->button();

   
       t1.button();
*/     
  /*
  const int a = 10;
    int *b = NULL;
    b = const_cast<int *>(&a);// With const_cast I have modified using b or changing a value 

    cout<<"\nThe Value of a and b  :" <<" "<< a << " " << *b;
     
    *b = 25;
    
    cout<<"\nThe Value of a and b  :" <<" "<< a << " " << *b <<endl;
  */
      
    return 0;
}
