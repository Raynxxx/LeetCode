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
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int limit = (n + 1) / 2;
        for (int i = 0; i < limit; ++i) {
            for (int j = 0; j < limit; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = tmp;

                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[j][n - i - 1] = matrix[i][j];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
            }
        }
    }
};


int main() {
    Solution solution;

    return 0;
}
