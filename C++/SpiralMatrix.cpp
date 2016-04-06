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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if (matrix.size() == 0) {
            return ret;
        }
        m = matrix.size();
        n = matrix[0].size();
        for (int i = 0; i < (m + 1) / 2 && i < (n + 1) / 2; ++i) {
            spiralTraverse(matrix, ret, i, i);
        }
        return ret;
    }

private:
    void spiralTraverse(vector<vector<int>>& matrix, vector<int>& result, int px, int py) {
        for (int j = py; j < n - py; ++j) {
            result.push_back(matrix[px][j]);
        }
        for (int i = px + 1; i < m - px; ++i) {
            result.push_back(matrix[i][n - py - 1]);
        }
        if (px != m - px - 1) {
            for (int j = n - py - 2; j >= py; --j) {
                result.push_back(matrix[m - px - 1][j]);
            }
        }
        if (py != n - py - 1) {
            for (int i = m - px - 2; i > px; --i) {
                result.push_back(matrix[i][py]);
            }
        }
    }

    int m;
    int n;
};

int main() {
    Solution solution;

    vector<vector<int>> arr = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 }
    };

    auto ret = solution.spiralOrder(arr);
    for (auto v : ret) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
