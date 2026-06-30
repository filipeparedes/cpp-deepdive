#include <iostream>
#include <thread>
#include <chrono>

void downloadFile(int fileId);


/*
    Create a simulated heavy workload (like downloading files) 
    and execute multiple instances of it simultaneously using std::thread.
    Observe the interleaved execution and properly join them before exiting.
*/
int main() {
    std::cout << "[Main] Launching threads...\n";
    
    std::thread t1(downloadFile, 12);
    std::thread t2(downloadFile, 56);

    std::cout << "[Main] Threads are running in the background... \n";

    t1.join();
    t2.join();

    std::cout << "[Main] All downloads complete. Exiting.\n";
}

void downloadFile(int fileId) {
    std::cout << "[Worker] Starting download " << fileId << "...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "[Worker] Finished download " << fileId << std::endl;
}

