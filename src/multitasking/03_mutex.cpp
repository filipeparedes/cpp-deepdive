#include <iostream>
#include <thread>
#include <mutex>


void unsafeIncrement();
void safeIncrement();

int sharedCounter = 0;

std::mutex counterMutex;

/*
    Demonstrate a data race by having two threads modify a shared 
    variable simultaneously. Then, introduce std::mutex and 
    std::lock_guard to synchronize access and fix the corruption.
*/
int main(){
    std::thread t1(unsafeIncrement);
    std::thread t2(unsafeIncrement);
    t1.join();
    t2.join();

    std::cout << "Unsafe Counter: " << sharedCounter << std::endl;

    sharedCounter = 0;

    std::thread t3(safeIncrement);
    std::thread t4(safeIncrement);
    t3.join();
    t4.join();

    std::cout << "Safe Counter: " << sharedCounter << std::endl;
}

void unsafeIncrement(){
    for (int i=0; i<1000000; i++){
        sharedCounter++;
    }
}

void safeIncrement(){
    for (int i=0; i<1000000; i++){
        // Use lock_guard instead of lock() and unlock(), as it automatically unlocks
        // at the closing brace. If code throws exception or returns eaarly between lock()
        // and unlock(), the mutex will remain locked forever.
        std::lock_guard<std::mutex> lock(counterMutex);
        sharedCounter++;
    }
}