#include<iostream>
#include<thread>
#include<mutex>
#include<vector>
#include<string>
#include<ctime>
using namespace std;

const int NumberofPhilosopher = 5;

vector<mutex> mtx(NumberofPhilosopher);

class Philosopher
{

  public:

  int l_chopstick;

  int r_chopstick;

  string p_name;

  int state;

  Philosopher(int L_Ch,int R_Ch,string P_Name,int State):l_chopstick(L_Ch),r_chopstick(R_Ch),p_name(P_Name),state(State){}

  void eat()
  {
    while(true)
    {
      std::lock(mtx[l_chopstick],mtx[r_chopstick]);

      unique_lock<mutex> lk(mtx[l_chopstick],adopt_lock);

      unique_lock<mutex> lk1(mtx[r_chopstick],adopt_lock);
	  
	  cout<< p_name << "is Eating " << endl;

      state = 2;

      cout<< p_name << "is Thinking" << endl;

      state = 1;

      this_thread::sleep_for(chrono::seconds(1));


     }
  }
};

//int i = 10 // only 10 will be moved 
//string var = "Sunny"; var =""; 

int main()
{
  cout << mtx.size() << endl;

  vector<Philosopher> p1;

  vector<thread> vec(NumberofPhilosopher);

  for(int it = 0;it<NumberofPhilosopher;it++)
  {
    if(it == (NumberofPhilosopher-1))
    {
      p1.push_back(Philosopher(it,0,"P"+to_string(it),1));
	}

    else
    {
      p1.push_back(Philosopher(it,it+1,"P"+to_string(it),1));
    }
  }

    for(int i=0;i<NumberofPhilosopher;i++)
    {
        vec[i] = thread(&Philosopher::eat,&p1[i]);
    }


  for( auto &e:vec)
  {
    e.join();
  }
  
  /*
 Philosopher p1(0,1,"P1",1),p2(1,2,"P2",1),p3(2,3,"P3",1),p4(3,4,"P4",1),p5(4,0,"P5",1);

  thread t1(&Philosopher::eat,&p1);

  thread t2(&Philosopher::eat,&p2);

  thread t3(&Philosopher::eat,&p3);

  thread t4(&Philosopher::eat,&p4);

  thread t5(&Philosopher::eat,&p5);

  t1.join();

  t2.join();

  t3.join();

  t4.join();

  t5.join();
*/
  return 0;
}
