#include<iostream>
#include<string>
using namespace std;

int main()
{
    std::string str = "Rizwan is a guy with bigger goals and dreams.";
    
     size_t found = str.find("bigger");
     
    if(found!=string::npos)
    cout << found << endl;
    
    found = str.find("goals",found+1,4);
    
    if(found!=string::npos)
    cout << "Goal was found at " << found  << endl;
    
    found = str.find("dreams",found+1,6);
    
    if(found!=string::npos)
    cout << "Dreams were found at " << found << endl;
    
    found = str.find('.');
    if(found!=string::npos)
    cout << "Dot was found at " << found << endl;
     
    return 0;
}