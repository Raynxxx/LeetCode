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
    vector<vector<int>> generateMatrix(int n) {
        this->n = n;
        this->m = n;
        vector<vector<int>> matrix(n);
        for_each(matrix.begin(), matrix.end(), [n](vector<int>& v) { v.resize(n); });
        int start = 1;
        for (int i = 0; i < (n + 1) / 2; ++i) {
            spiralTraverse(matrix, i, i, start);
        }
        vector<int> ret;
        for_each(matrix.begin(), matrix.end(), [ret](vector<int>& v) {
            for_each(v.begin(), v.end(), [ret](int val) {
                ret.push_back(val);
            });
        });
    }

private:
    void spiralTraverse(vector<vector<int>>& matrix, int px, int py, int& start) {
        for (int j = py; j < n - py; ++j) {
            matrix[px][j] = start++;
        }
        for (int i = px + 1; i < m - px; ++i) {
            matrix[i][n - py - 1] = start++;
        }
        if (px != m - px - 1) {
            for (int j = n - py - 2; j >= py; --j) {
                matrix[m - px - 1][j] = start++;
            }
        }
        if (py != n - py - 1) {
            for (int i = m - px - 2; i > px; --i) {
                matrix[i][py] = start++;
            }
        }
    }

    int n;
    int m;
};

int main() {
    return 0;
}
