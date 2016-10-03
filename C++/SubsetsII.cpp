//
// Subsets II
// Created by Rayn on 2016/10/3.
//
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    void dfs(int start, vector<int>& nums, vector<int>& tmp, vector<vector<int>>& ret) {
        ret.push_back(tmp);
        for (int i = start; i < nums.size(); ++i) {
            tmp.push_back(nums[i]);
            dfs(i + 1, nums, tmp, ret);
            tmp.pop_back();
            while (i < nums.size() - 1 && nums[i + 1] == nums[i]) {
                i++;
            }
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        dfs(0, nums, tmp, ret);
        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> sample = { 1, 2, 2 };
    auto ret = solution.subsetsWithDup(sample);
    for (auto i : ret) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

