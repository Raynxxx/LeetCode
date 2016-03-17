#include <map>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = lowerBound(nums, target);
        int right = upperBound(nums, target);
        if (left == right) {
            return vector<int>({ -1, -1 });
        } else {
            return vector<int>({ left, right - 1 });
        }
    }

private:
    int lowerBound(const vector<int>& nums, int target) {
        int size = nums.size();
        int first = 0, mid;
        int half, len = size;
        while (len > 0) {
            half = len >> 1;
            mid = first + half;
            if (target > nums[mid]) {
                first = mid + 1;
                len = len - half - 1;
            } else {
                len = half;
            }
        }
        return first;
    }

    int upperBound(const vector<int>& nums, int target) {
        int size = nums.size();
        int first = 0, mid;
        int half, len = size;
        while (len > 0) {
            half = len >> 1;
            mid = first + half;
            if (target < nums[mid]) {
                len = half;
            } else {
                first = mid + 1;
                len = len - half - 1;
            }
        }
        return first;
    }
};


int main() {
    Solution solution;
    vector<int> arr = { 5, 7, 7, 8, 8, 10 };
    auto ret = solution.searchRange(arr, 8);
    assert(ret == vector<int>({ 3, 4 }));
    ret = solution.searchRange(arr, 11);
    assert(ret == vector<int>({ -1, -1 }));
    ret = solution.searchRange(arr, 3);
    assert(ret == vector<int>({ -1, -1 }));

    arr = { 1 };
    ret = solution.searchRange(arr, 1);
    assert(ret == vector<int>({ 0, 0 }));
    return 0;
}
