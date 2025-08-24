#include<iostream>
using namespace std;

//Program to add two Complex numbers Overloading + Operator :-

class Complex 
{
    public:
    
    float real;
    
    float imag;
    
    Complex():real(0.0),imag(0.0){}
    
    Complex(float _real,float _imag):real(_real),imag(_imag){}
    
    Complex operator + (const Complex &rhs)
    {
        Complex result;
        
        result.real = real + rhs.real;
        result.imag = imag + rhs.imag;
        
        return result;
    }
    
    friend ostream& operator << (ostream &out, const Complex& rhs);
    
    void print()
    {   
        cout << "The real part is : " << real << endl;
        
        cout << "The imaginary part is : " << imag << endl;
        
        cout << "The Complex number is : " << real << "+i" << imag << endl;
        cout << "\n";
    }
    
};

    ostream& operator << (ostream& out, const Complex& rhs)
    {
        out << "The real part is : " << rhs.real << endl;
        
        out << "The imaginary part is : " << rhs.imag << endl;
        
        out << "The Complex number is : " << rhs.real << "+i" << rhs.imag << endl;
        out << "\n";
        
        return out;
    }

int main()
{
    Complex c1(3.14,5.86);
    
    cout << c1;
    
    Complex c2(3.14,5.86);
    
    cout << c2;
    
    Complex c3 = c1+c2;
    
    cout << c3;
    
    return 0;    
}