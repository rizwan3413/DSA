#include<iostream>
#include<cstring>
using namespace std;

void memsetsample()
{
    char* pch = new char[10];
    memset( pch, 'A', 10 );

    int* pn = new int[10];
    memset( pn, 0, sizeof(int)*10 );
    for( int nCount = 0; nCount < 10; nCount++ )
    {
        cout<<pch[nCount]<<" "<<pn[nCount]<<"\n";
    }
}

int main()
{

 memsetsample();

 return 0;
}

