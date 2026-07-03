#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>
#include <chrono>
#include <numeric>

/*
    Demonstrate the performance difference between sequential and 
    parallel execution policies (C++17) using std::sort on a massive dataset.
    Benchmark the execution time to observe the benefits of hardware parallelism.
*/
int main(){
    using namespace std::chrono;

    std::vector<int> v(10000000);
    //populate w/ decreasing values starting on 1
    std::iota(v.rbegin(), v.rend(), 1);

    std::vector<int> v2 = v;

    high_resolution_clock::time_point t1 = high_resolution_clock::now(); 
    std::sort(std::execution::seq, v.begin(), v.end());
    high_resolution_clock::time_point t2 = high_resolution_clock::now(); 

    long long seq_duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
    std::cout << "Sequential sort time: " << seq_duration << " ms\n";

    t1 = high_resolution_clock::now(); 
    std::sort(std::execution::par, v.begin(), v.end());
    t2 = high_resolution_clock::now(); 

    long long par_duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
    std::cout << "Parallel sort time: " << par_duration << " ms\n";
}