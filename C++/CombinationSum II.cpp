#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ret.clear();
        tmp.clear();
        sort(candidates.begin(), candidates.end());
        solve(0, 0, target, candidates);
        return ret;
    }

    void solve(int sum, int dep, int target, const vector<int>& candidates) {
        if (sum > target) return;
        if (sum == target) {
            ret.push_back(vector<int>(tmp));
            return;
        }
        int length = candidates.size();
        for (int i = dep; i < length; ++i) {
            tmp.push_back(candidates[i]);
            solve(sum + candidates[i], i + 1, target, candidates);
            tmp.pop_back();
            while (i < length - 1 && candidates[i] == candidates[i + 1]) {
                i++;
            }
        }
    }

private:
    vector<vector<int>> ret;
    vector<int> tmp;
};


int main() {
    Solution solution;
    vector<int> vec = { 10, 1, 2, 7, 6, 1, 5 };
    auto ret = solution.combinationSum2(vec, 8);
    for (int i = 0; i != ret.size(); ++i) {
        for (int j = 0; j != ret[i].size(); ++j) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}