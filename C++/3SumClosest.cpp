#include <map>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        if (size < 3) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int closest = 0x7fffffff;
        int ret = 0;
        for (int i = 0; i < size - 2; ++i) {
            int left = i + 1, right = size - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < target) {
                    if (target - sum < closest) {
                        closest = target - sum;
                        ret = sum;
                    }
                    left++;
                } else if (sum > target) {
                    if (sum - target < closest) {
                        closest = sum - target;
                        ret = sum;
                    }
                    right--;
                } else {
                    return sum;
                }
            }
        }
        return ret;
    }
};


int main() {
    Solution solution;
    vector<int> vec = { -1, 2, 1, -4 };
    auto ret = solution.threeSumClosest(vec, 1);
    assert(ret == 2);
    vec = { 4, -1, -4, 4 };
    ret = solution.threeSumClosest(vec, -1);
    assert(ret == -1);
    return 0;
}