#include <iostream>
#include <vector>

std::pair<int, int> findPairWithSum(const std::vector<int>& num, const int target);

/*
    Implement the classic Two Sum (Sorted) problem. 
    Given a sorted array of integers and a target sum, 
    find the two numbers that add up to that target using 
    two pointers moving inward from both ends.
*/
int main() {
    std::vector<int> numbers = {2, 7, 11, 15, 20, 27};
    int target = 35;

    std::pair<int, int> res = findPairWithSum(numbers, target);

    std::cout << target << " = " << res.first << " + " << res.second << std::endl;

    return 0;
}

std::pair<int, int> findPairWithSum(const std::vector<int>& nums, const int target) {
    int p1 = 0;
    int p2 = nums.size()-1;

    while (p2 > p1) {
        int sum = nums[p1] + nums[p2];

        if (sum == target) return {nums[p1], nums[p2]};
        else if (sum > target) p2--;
        else if (sum < target) p1++;
    }

    return {-1, -1};
}