//1 Producer thread
//1 Consumer thread
//Producer Thread is producing updating the queue at the end
//Consumer Thread is consuming from the begining  and updating the queue

#include <iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<deque>
using namespace std;

mutex mtx;
condition_variable cv;

deque<int> dq;

int inventory_size  = 20;

int count = 0;

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
		this_thread::sleep_for(chrono::milliseconds(1));
    }

}

void Consume()
{
    cout << "Consumer Started consuming" << endl;
    while(true)
    {
        unique_lock<mutex> ul(mtx);

        cv.wait(ul,[](){return count!=0;});
        cout<< " Consuming "  << dq.back() << endl;
        dq.pop_back();
        count--;
        cv.notify_all();
        this_thread::sleep_for(chrono::milliseconds(1));
    }
}

void printDeque()
{
    unique_lock<mutex> ul1(mtx);

    cv.wait(ul1);

     cout << "Printing Deque" << endl;

    for(const auto &e : dq)

    cout << e << " ";
	cout << "\n";
}

int main() {
  thread t1(Produce);//Global function
  thread t2(Consume);
  thread t3(printDeque);

  t1.join();
  t2.join();
  t3.join();

  return 0;
}

