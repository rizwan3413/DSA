#include<iostream>
using namespace std;


class Test 
{
    public:
    
    int x;
    
    Test(){}
    
    Test(int y):x(y){}
    
    Test operator + (const Test &rhs)
    {
        Test result = x + rhs.x; 
        return result;
    }
    
    
    void print()
    {   
        cout << x << endl;
        
        cout << "\n";
    }
    
};

int main()
{
    Test a1(10);
    
    a1.print();
    
    Test a2(10);
    
    a2.print();
    
    Test a3 = a1+a2;
    
    a3.print();
    
    return 0;    
}