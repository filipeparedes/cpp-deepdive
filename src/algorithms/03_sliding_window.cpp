#include <iostream>
#include <ostream>
#include <vector>

int maxSubarraySum(const std::vector<int>& v, int k);

/*
    Implement the Sliding Window algorithm.
    Given an array of integers and an integer k, find the maximum 
    sum of a contiguous subarray of size k. This must be achieved 
    with an O(N) time complexity by sliding the window across the array.
*/
int main(){
    std::vector<int> numbers = {2, 1, 5, 1, 3, 2};
    int k = 3;

    int max = maxSubarraySum(numbers, k);

    std::cout << "Maximum sum: " << max << std::endl;

    return 0;
}

int maxSubarraySum(const std::vector<int>& v, int k) {
    if (v.size() < k) return -1;

    int windowSum = 0;
    int maxSum = 0;

    //calc sum for the "first window"
    for (int i = 0; i<k; i++){
        windowSum += v[i];
    }

    maxSum = windowSum;
    
    // "slide" the window until the end
    for (int i = k; i<v.size(); i++){
        windowSum += v[i] - v[i-k];

        if (windowSum > maxSum)
            maxSum = windowSum;
    }

    return maxSum;
}