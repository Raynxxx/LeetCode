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
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) {
            return true;
        }
        int maxReach = nums[0];
        if (maxReach == 0) {
            return false;
        }
        for (int i = 1; i < size; ++i) {
            if (maxReach >= i && i + nums[i] >= size - 1) {
                return true;
            }
            if (maxReach <= i && nums[i] == 0) {
                return false;
            }
            if (i + nums[i] > maxReach) {
                maxReach = i + nums[i];
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> arr = { 2, 3, 1, 1, 4 };
    auto ret = solution.canJump(arr);
    assert(ret == true);
    arr = { 3, 2, 1, 0, 4 };
    ret = solution.canJump(arr);
    assert(ret == false);
    arr = { 2, 5, 0, 0 };
    ret = solution.canJump(arr);
    assert(ret == true);
    arr = { 0, 2, 3 };
    ret = solution.canJump(arr);
    assert(ret == false);
    return 0;
}
