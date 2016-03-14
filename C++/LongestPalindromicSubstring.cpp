#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    string expandAroundCenter(const string& s, int l, int r) {
        int length = s.length();
        while (0 <= l && r <= length - 1 && s[l] == s[r]) {
            l--, r++;
        }
        return s.substr(l + 1, r - l - 1);
    }
    string longestPalindrome(string s) {
        int length = s.length();
        if (length <= 1) return s;
        string longest = s.substr(0, 1);
        for (int i = 0; i < length - 1; ++i) {
            string p1 = expandAroundCenter(s, i, i);
            if (p1.length() > longest.length()) {
                longest = p1;
            }
            string p2 = expandAroundCenter(s, i, i + 1);
            if (p2.length() > longest.length()) {
                longest = p2;
            }
        }
        return longest;
    }
};


int main() {
    Solution solution;
    auto ret = solution.longestPalindrome("aba");
    assert(ret == "aba");
    ret = solution.longestPalindrome("jqcabacd");
    assert(ret == "cabac");
    ret = solution.longestPalindrome("jqcabbacd");
    assert(ret == "cabbac");
    ret = solution.longestPalindrome("");
    assert(ret == "");
    ret = solution.longestPalindrome("a");
    assert(ret == "a");
    return 0;
}