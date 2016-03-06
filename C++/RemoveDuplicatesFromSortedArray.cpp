#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto end = unique(nums.begin(), nums.end());
        nums.erase(end, nums.end());
        return nums.size();
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 1, 1, 2 };
    auto ret = solution.removeDuplicates(nums);
    assert(ret == 2);
    return 0;
}