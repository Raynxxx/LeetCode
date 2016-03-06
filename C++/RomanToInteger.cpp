#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int length = s.length();
        int ret = toNumber(s[0]);
        for (int i = 1; i < length; ++i) {
            if (toNumber(s[i - 1]) < toNumber(s[i])) {
                ret += toNumber(s[i]) - 2 * toNumber(s[i - 1]);
            } else {
                ret += toNumber(s[i]);
            }
        }
        return ret;
    }
    int toNumber(const char& ch) {
        switch (ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }
};

int main() {
    Solution solution;
    int ret;
    ret = solution.romanToInt("DCXXI");
    assert(ret == 621);
    return 0;
}