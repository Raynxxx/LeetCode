//
// Word Search
// Created by Rayn on 16/9/28.
//
#include <map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    const int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool search(int sx, int sy, vector<vector<bool>>& visited,
                vector<vector<char>>& board, const string &word, int pos) {
        if (visited[sx][sy]) return false;
        if (word[pos] == board[sx][sy]) {
            if (pos == word.length() - 1) return true;
        } else {
            return false;
        }
        visited[sx][sy] = true;
        bool ret = false;
        for (int i = 0; i < 4; ++i) {
            int nx = sx + dir[i][0];
            int ny = sy + dir[i][1];
            if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size()) {
                continue;
            }
            ret = ret || search(nx, ny, visited, board, word, pos + 1);
            if (ret) break;
        }
        visited[sx][sy] = false;
        return ret;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = (int) board.size();
        int n = (int) board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    if (search(i, j, visited, board, word, 0)) return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> sample = {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'E', 'S'},
            {'A', 'D', 'E', 'E'}
    };
    auto ret = solution.exist(sample, "ABCEFSADEESE");
    cout << boolalpha << ret << endl;
    return 0;
}
