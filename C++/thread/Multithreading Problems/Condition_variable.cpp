#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

std::mutex mtx;

std::condition_variable cv;

long balance = 0;

using namespace std;

void addMoney(int money)
{
    unique_lock<mutex> ul(mtx);
   
    balance+=money;
    cout << "Amount of " << money << " has been added to the account" << endl;
    cout << "Balance is " << balance << endl;
    cv.notify_one();
}


void withdrawMoney(int money)
{
   
    unique_lock<mutex> ul(mtx);
    cv.wait(ul,[](){return balance!=0? true : false; });
    balance-=money;
    cout << "Amount of " << money << " has been deducted from the account" << endl;
    cout << "Balance is " << balance << endl;
   
}


int main()
{
    thread t1(withdrawMoney,500);
    thread t2(addMoney,500);
   
     t1.join();
     t2.join();
     
    return 0;
}