#include<iostream>
using namespace std;

class Test
{
 public:

 char p[4];
 string Hdop=0;
 string GnssLockStatus=2;
 string NumSats=0;
 string GnssSpeed=0.000000;
 string Altitude=0.000000;
 string Heading=0;
 string Longitude=0.000000;
 string Latitude=0.000000
};

int main()
{
 int a = 25; 

 int b;

 Test a1;

 a1 = *reinterpret_cast<Test*>(&a);

 for(int i = 0;i<4;i++)
 {
 cout << a1.p[i] << endl;
 }

 b = *reinterpret_cast<int *>(&a1.p);

 cout << b << endl;

 return 0;

}
