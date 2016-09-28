//
// Set Matrix Zeroes
// Created by Rayn on 16/9/27.
//
#include <map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();

        bool first_row_zero = false;
        bool first_col_zero = false;
        // judge first row
        for (int i = 0; i < n; ++i) {
            if (matrix[0][i] == 0) {
                first_row_zero = true;
                break;
            }
        }
        // judge first col
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                first_col_zero = true;
                break;
            }
        }
        // record
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // set cols
        for (int i = 1; i < n; ++i) {
            if (matrix[0][i] == 0) {
                for (int j = 1; j < m; ++j) {
                    matrix[j][i] = 0;
                }
            }
        }
        // set rows
        for (int i = 1; i < m; ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (first_row_zero) {
            for (int i = 0; i < n; ++i) {
                matrix[0][i] = 0;
            }
        }
        if (first_col_zero) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main() {
    Solution solution;
    return 0;
}
