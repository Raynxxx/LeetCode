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
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        gao(0, nums, ret);
        return ret;
    }

private:
    void gao(int begin, vector<int>& nums, vector<vector<int>>& ret) {
        if (begin == nums.size()) {
            ret.push_back(nums);
            return;
        }
        for (int i = begin; i < (int) nums.size(); ++i) {
            swap(nums[begin], nums[i]);
            gao(begin + 1, nums, ret);
            swap(nums[begin], nums[i]);
        }
    }
};


int main() {
    Solution solution;
    vector<int> vec = { 1, 2, 3 };
    auto ret = solution.permute(vec);
    for (auto& per : ret) {
        copy(per.begin(), per.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
    return 0;
}
