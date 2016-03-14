#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ret.clear();
        tmp.clear();
        sort(candidates.begin(), candidates.end());
        solve(0, 0, target, candidates);
        return ret;
    }
    void solve(int sum, int dep, int target, vector<int>& candidates) {
        if (sum > target) return;
        if (sum == target) {
            ret.push_back(vector<int>(tmp));
            return;
        }
        for (int i = dep; i < (int) candidates.size(); ++i) {
            tmp.push_back(candidates[i]);
            solve(sum + candidates[i], i, target, candidates);
            tmp.pop_back();
        }
    }

private:
    vector<vector<int>> ret;
    vector<int> tmp;
};


int main() {
    Solution solution;
    vector<int> vec = { 2, 3, 6, 7 };
    auto ret = solution.combinationSum(vec, 7);
    for (int i = 0; i != ret.size(); ++i) {
        for (int j = 0; j != ret[i].size(); ++j) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}