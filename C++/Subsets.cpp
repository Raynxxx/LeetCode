//
// Subsets
// Created by Rayn on 16/9/28.
//
#include <map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void dfs(int start, vector<int>& nums, vector<int>& tmp, vector<vector<int>>& ret) {
        ret.push_back(tmp);
        for (int i = start; i < nums.size(); ++i) {
            tmp.push_back(nums[i]);
            dfs(i + 1, nums, tmp, ret);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> tmp;
        dfs(0, nums, tmp, ret);
        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> sample = { 1, 2, 3 };
    auto ret = solution.subsets(sample);
    for (auto i : ret) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}


