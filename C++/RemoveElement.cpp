#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> ret;
        auto it = nums.begin();
        for (; it != nums.end(); ++it) {
            if (*it != val) {
                ret.push_back(*it);
            }
        }
        swap(ret, nums);
        return nums.size();
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 1, 1, 2, 5, 6, 7 };
    auto ret = solution.removeElement(nums, 1);
    assert(ret == 4);
    return 0;
}