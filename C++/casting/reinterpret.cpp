#include<iostream>
#include<stdint.h>
using namespace std;

int main()

{
    float GPS = 355.1254;
    int var = (int)GPS;// Convertion using C style  Casting 
    int *Lattitude = reinterpret_cast<int *>(&GPS);
    float *Lat = reinterpret_cast<float *>(Lattitude);
    char *ptr = (char *)(&GPS);
    for(int i = 0 ; i<4;i++)
	{
	    cout<<"Value at index  "<< i <<" "<< (int)*ptr << endl;
        ptr++;
        }    
    cout<<" The Value of GPS is : "<< GPS<< endl;
    cout<<" The Value of Lattitude is: "<< *Lattitude<<endl;
    cout<<" The Value of Lat " << *Lat << endl;
    cout<<" The value of var is "<< var<< endl;// The Data after Decimal gets lost hence C style or Static cast is not useful if we want to view the contents after the decimal point//Thus reinterpret Cast solves that problem
    return 0;
}

