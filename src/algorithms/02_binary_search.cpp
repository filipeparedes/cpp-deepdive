#include <vector>
#include <iostream>

int binarySearch(const std::vector<int>& vec, const int target);

/*
    Implement the classic Binary Search algorithm.
    Given a sorted array of integers and a target value,
    efficiently locate the target by repeatedly dividing 
    the search interval in half using two pointers.
*/
int main() {
    std::vector<int> numbers = {2, 7, 11, 15, 20, 27, 32, 55, 76, 89, 112, 123, 162};
    int target = 89;

    int tarIdx = binarySearch(numbers, target);

    std::cout << "The target is located at the index: " << tarIdx << std::endl;
}

int binarySearch(const std::vector<int>& vec, const int target){
    int left = 0;
    int right = vec.size()-1;

    while (left <= right){
        int mid = left + (right - left) /2;

        if (vec[mid] == target){
            return mid;
        } 
        else if (vec[mid] < target){
            left = mid+1;
        } else {
            right = mid-1;
        }
    }

    return -1;
}