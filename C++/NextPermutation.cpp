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
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return;

        int i = size - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = size - 1;
            while (j > i && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        int left = i + 1, right = size - 1;
        while (left < right) {
            swap(nums[left], nums[right]);
            left++, right--;
        }
    }

    
};


int main() {
    Solution solution;
    vector<int> arr = { 1, 2, 3 };
    solution.nextPermutation(arr);
    assert(arr == vector<int>({ 1, 3, 2 }));
    arr = { 3, 2, 1 };
    solution.nextPermutation(arr);
    assert(arr == vector<int>({ 1, 2, 3 }));
    arr = { 1, 1, 5 };
    solution.nextPermutation(arr);
    assert(arr == vector<int>({ 1, 5, 1 }));
    return 0;
}
