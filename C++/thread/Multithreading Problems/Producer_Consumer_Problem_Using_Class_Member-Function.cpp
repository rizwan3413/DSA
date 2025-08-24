#include<iostream>
#include<thread>
#include<deque>
#include<mutex>
#include<condition_variable>
using namespace std;

mutex mtx;
condition_variable cv;

deque<int> dq;

class Producer
{
    public:
    static int count;
    static int inventory_size;

    void Produce()
    {
        int i =0;

        cout << " Producing Started" << endl;

        while(true)
        {
            unique_lock<mutex> ul(mtx);
            cv.wait(ul,[](){return count<inventory_size;});
            dq.push_back(i);
            cout<< " Producing :" << i << endl;
            i++;
            count++;
            cv.notify_all();
        }
    }

};

int Producer ::count = 0;
int Producer ::inventory_size = 20;

class Consumer
{
    public:

    void Consume()
    {
        cout << "Consumer Started consuming" << endl;
        while(true)
        {
            unique_lock<mutex> ul(mtx);

            cv.wait(ul,[](){return Producer::count!=0;});
            cout<< " Consuming "  << dq.back() << endl;
            dq.pop_back();
            Producer::count--;
            cv.notify_all();
        }
    }

};
int main()
{
    Producer p1;
    Consumer c1;

    thread t1(&Producer::Produce,&p1);
    thread t2(&Consumer::Consume,&c1);
    thread t3([]()
    {
        unique_lock<mutex> ul1(mtx);

        cv.wait(ul1);
        cout << "Printing Deque" << endl;

        for(const auto &e : dq)

        cout << e << " ";

        cout << "\n";

    });

    t1.join();
    t2.join();
    t3.join();

    return 0;
}

