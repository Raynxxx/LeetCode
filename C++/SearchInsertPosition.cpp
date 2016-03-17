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
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        int left = 0, right = size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target > nums[mid]) {
                left = mid + 1;
            } else if (target < nums[mid]) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return left;
    }
};


int main() {
    Solution solution;
    vector<int> arr = { 1, 3, 5, 6 };
    int pos = solution.searchInsert(arr, 5);
    assert(pos == 2);
    pos = solution.searchInsert(arr, 2);
    assert(pos == 1);
    pos = solution.searchInsert(arr, 7);
    assert(pos == 4);
    pos = solution.searchInsert(arr, 0);
    assert(pos == 0);
    return 0;
}
