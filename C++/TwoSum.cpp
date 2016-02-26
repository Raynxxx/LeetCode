#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        unordered_map<int, int> hash;
        for (auto i = 0; i != nums.size(); ++i) {
            if (!hash.count(nums[i])) {
                hash.insert(make_pair(nums[i], i));
            }
            if (hash.count(target - nums[i])) {
                int id = hash[target - nums[i]];
                if (id < i) {
                    ret.push_back(hash[target - nums[i]]);
                    ret.push_back(i);
                    break;
                }
            }
        }
        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 3, 2, 4 };
    int target = 6;
    auto ret = solution.twoSum(nums, target);
    for (auto& k : ret) {
        cout << k << endl;
    }
    return 0;
}