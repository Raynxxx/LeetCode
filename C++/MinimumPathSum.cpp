//
// Minimum Path Sum
// Created by Rayn on 16/9/27.
//
#include <map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    const static int MAX_NUM;

    int minPathSum(vector<vector<int>>& grid) {
        int m = (int) grid.size();
        if (m == 0) return 0;
        int n = (int) grid[0].size();
        if (n == 0) return 0;
        vector<vector<int>> dp(m, vector<int>(n, Solution::MAX_NUM));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; ++j) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};

const int Solution::MAX_NUM = 0x3f3f3f3f;

int main() {
    vector<vector<int>> sample = {
            {1, 2, 3, 4},
            {1, 2, 3, 4},
            {1, 2, 3, 4}
    };
    Solution solution;
    cout << solution.minPathSum(sample) << endl;
    return 0;
}