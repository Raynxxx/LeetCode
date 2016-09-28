//
// Combinations
// Created by Rayn on 16/9/28.
//
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void dfs(int n, int start, int level, vector<int>& tmp, vector<vector<int>>& ret) {
        if (level <= 0) {
            ret.push_back(tmp);
            return;
        }
        for (int i = start; i <= n; ++i) {
            tmp.push_back(i);
            dfs(n, i + 1, level - 1, tmp, ret);
            tmp.pop_back();
        }

    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> tmp;
        dfs(n, 1, k, tmp, ret);
        return ret;
    }
};

int main() {
    Solution solution;
    auto ret = solution.combine(4, 2);
    return 0;
}


