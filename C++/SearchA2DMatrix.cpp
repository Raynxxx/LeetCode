//
// Search a 2D Matrix
// Created by Rayn on 16/9/28.
//
#include <map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = (int) (matrix.size() - 1);
        int row = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (target < matrix[mid][0]) {
                r = mid - 1;
            } else if (target > matrix[mid][0]) {
                l = mid + 1;
                row = mid;
            } else {
                return true;
            }
        }
        if (row < 0)
            return false;
        l = 0, r = (int) (matrix[0].size() - 1);
        while (l <= r) {
            int mid = (l + r) / 2;
            if (target < matrix[row][mid]) {
                r = mid - 1;
            } else if (target > matrix[row][mid]) {
                l = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> sample = {
            {1,  3,  5,  7},
            {10, 11, 16, 20},
            {23, 30, 34, 50}
    };
    cout << boolalpha << solution.searchMatrix(sample, 11) << endl;
    sample = {
            {1}
    };
    cout << boolalpha << solution.searchMatrix(sample, 0) << endl;
    return 0;
}

