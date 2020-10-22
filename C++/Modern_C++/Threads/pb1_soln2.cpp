/* __Problem1 Solution__Atomic Variable

 std::atomic<int> val(100)
 g++ pb1_soln2.cpp -lpthread && ./a.out

*/
#include <iostream>
#include <thread>
#include <string>
#include <mutex>

#define print(msg) std::cout << msg << std::endl
#define str(x) std::to_string(x)
constexpr int max =10000; 

int val = 100;   // Shared Resource for both the threads
std::mutex m1;    // Declared Globally

void inc(){
    print("Thread Increase");
    m1.lock();                 // Critical Section
    for(int i=0;i<=max;i++){
      val++;   
    }
    m1.unlock();   //Unlock to for other threads
}

void dec(){
    print("Thread Decrease");
    m1.lock();  
    for(int i=0;i<=max;i++){
     val--;  
    }
    m1.unlock();
}

int main(){
    print("Main-- Welcome");
    std::thread t1(inc);    // Created Thread1 for fsample
    std::thread t2(dec); // 2nd Parallel Thread
    t1.join();
    t2.join();
    print("Final Val:"+str(val));
    print("End");
    return 0;

}
