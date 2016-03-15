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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        int size = nums.size();
        if (size < 4) {
            return ret;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < size - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int left = j + 1, right = size - 1;
                int sure = nums[i] + nums[j];
                while (left < right) {
                    int sum = sure + nums[left] + nums[right];
                    if (sum == target) {
                        vector<int> tmp = {
                            nums[i], nums[j], nums[left], nums[right]
                        };
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
        }
        return ret;
    }
};


int main() {
    Solution solution;
    vector<int> vec = { 1, 0, -1, 0, -2, 2 };
    auto ret = solution.fourSum(vec, 0);
    for (auto& v : ret) {
        for (auto& num : v) {
            cout << num << " ";
        }
        cout << endl;
    }
    vec = { 0, 0, 0, 0 };
    ret = solution.fourSum(vec, 0);
    for (auto& v : ret) {
        for (auto& num : v) {
            cout << num << " ";
        }
        cout << endl;
    }
    vec = { -3, -2, -1, 0, 0, 1, 2, 3 };
    ret = solution.fourSum(vec, 0);
    for (auto& v : ret) {
        for (auto& num : v) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}