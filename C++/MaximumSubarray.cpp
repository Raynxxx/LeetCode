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
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int sum = 0, ret = nums[0];
        for (int i = 0; i < size; ++i) {
            if (sum < 0) {
                sum = 0;
            }
            sum += nums[i];
            ret = max(ret, sum);
        }
        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    auto ret = solution.maxSubArray(arr);
    assert(ret == 6);
    arr = { 1 };
    ret = solution.maxSubArray(arr);
    assert(ret == 1);
    return 0;
}
