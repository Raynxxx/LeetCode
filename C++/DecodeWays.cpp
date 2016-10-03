//
// Decode Ways
// Created by Rayn on 2016/10/3.
//
#include <map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        size_t length = s.length();
        if (length == 0 || s[0] == '0') return 0;
        vector<int> dp(length + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= length; ++i) {
            dp[i] = 0;
            if (s[i - 1] != '0') {
                dp[i] = dp[i - 1];
            }
            int last2 = stoi(s.substr(i - 2, 2));
            if (last2 >= 10 && last2 <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[length];
    }
};

int main() {
    Solution solution;
    cout << solution.numDecodings("101") << endl;
    return 0;
}

