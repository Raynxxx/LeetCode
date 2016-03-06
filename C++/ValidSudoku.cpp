#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.size() != 9) {
            return false;
        }
        for (int i = 0; i != board.size(); ++i) {
            if (board[i].size() != 9) {
                return false;
            }
        }
        cout << "flag" << endl;
        bool hash[10] = { false };
        for (int i = 0; i < 9; ++i) {
            fill_n(hash, 10, false);
            for (int j = 0; j < 9; ++j) {
                if (!check(hash, board[i][j])) {
                    return false;
                }
            }
        }
        cout << "flag" << endl;
        for (int j = 0; j < 9; ++j) {
            fill_n(hash, 10, false);
            for (int i = 0; i < 9; ++i) {
                if (!check(hash, board[i][j])) {
                    return false;
                }
            }
        }
        cout << "flag" << endl;
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                fill_n(hash, 10, false);
                for (int k = 0; k < 9; ++k) {
                    if (!check(hash, board[i+k/3][j+k%3])) {
                        return false;
                    }
                }
            }
        }
        cout << "flag" << endl;
        return true;
    }
    bool check(bool hash[], char ch) {
        if (ch == '.') return true;
        int num = ch - '0';
        if (num < 0 || num > 9 || hash[num]) {
            return false;
        } else {
            hash[num] = true;
        }
        return true;
    }
};


int main() {
    Solution solution;
    return 0;
}