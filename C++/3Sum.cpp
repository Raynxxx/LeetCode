#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        int size = nums.size() - 2;
        for (int i = 0; i < size; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1, right = nums.size() - 1;
            int target = -nums[i];
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == target) {
                    vector<int> tmp = { nums[i], nums[left], nums[right] };
                    ret.push_back(tmp);
                    int uniqueLeft = left + 1, uniqueRight = right - 1;
                    while (uniqueLeft < right && nums[uniqueLeft] == nums[left]) {
                        uniqueLeft++;
                    }
                    while (uniqueRight > left && nums[uniqueRight] == nums[right]) {
                        uniqueRight--;
                    }
                    left = uniqueLeft, right = uniqueRight;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        auto end = unique(ret.begin(), ret.end());
        ret.resize(distance(ret.begin(), end));
        return ret;
    }
};

bool equal3(const vector<int>& nums) {
    if (nums.size() != 3) return false;
    int sum = 0;
    for (int i = 0; i != nums.size(); ++i) {
        sum += nums[i];
    }
    return sum == 0;
}

int main() {
    Solution solution;
    vector<int> nums = { -1, 0, 1, 2, -1, -4 };
    auto ret = solution.threeSum(nums);
    for (int i = 0; i != ret.size(); ++i) {
        assert(equal3(ret[i]));
        cout << ret[i].size() << endl;
    }
    return 0;
}