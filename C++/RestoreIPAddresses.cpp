//
// Restore IP Addresses
// Created by Rayn on 2016/10/3.
//
#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(string& x) {
        int num = stoi(x);
        if (x.length() == 1 && num >= 0 && num <= 9) return true;
        if (x.length() == 2 && num >= 10 && num <= 99) return true;
        if (x.length() == 3 && num >= 100 && num <= 255) return true;
        return false;
    }

    string joinVector(const vector<string>& vec, string separator) {
        string ret;
        for (int i = 0; i < vec.size(); ++i) {
            ret += vec[i];
            if (i < vec.size() - 1) {
                ret += separator;
            }
        }
        return ret;
    }

    void dfs(int start, string& origin, vector<string>& ips, vector<string>& ret) {
        if (start == origin.length()) {
            if (ips.size() == 4) {
                ret.push_back(joinVector(ips, "."));
            }
            return;
        }
        for (int k = 1; k <= 3 && start + k - 1 < origin.length(); ++k) {
            string cur = origin.substr(start, k);
            if (isValid(cur)) {
                ips.push_back(cur);
                dfs(start + k, origin, ips, ret);
                ips.pop_back();
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        size_t length = s.length();
        vector<string> ret;
        if (length < 4 || length > 12) return ret;

        vector<string> ips;
        dfs(0, s, ips, ret);
        return ret;
    }
};

int main() {
    Solution solution;
    solution.restoreIpAddresses("010010");
    return 0;
}
