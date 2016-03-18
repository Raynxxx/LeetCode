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
    string multiply(string num1, string num2) {
        int len1 = num1.length(), len2 = num2.length();
        if (len1 == 0 || len2 == 0) {
            return "";
        }

        vector<int> digits(len1 + len2, 0);
        string ret(len1 + len2, '0');
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int j = 0; j < len2; ++j) {
            int below = num2[j] - '0';
            for (int i = 0; i < len1; ++i) {
                int up = num1[i] - '0';
                digits[i + j] += up * below;
            }
        }
        int carry = 0;
        for (int i = 0; i < (int) digits.size(); ++i) {
            int cur = digits[i] + carry;
            carry = cur / 10;
            ret[i] = cur % 10 + '0';
        }
        reverse(ret.begin(), ret.end());
        int start = ret.find_first_not_of('0');
        if (start == string::npos) {
            start = ret.size() - 1;
        }
        return ret.substr(start);
    }
};


int main() {
    Solution solution;
    auto ret = solution.multiply("123", "123");
    assert(ret == "15129");
    ret = solution.multiply("99", "99");
    assert(ret == "9801");
    ret = solution.multiply("123", "3");
    assert(ret == "369");
    ret = solution.multiply("00", "00");
    assert(ret == "0");
    ret = solution.multiply("15643", "0");
    assert(ret == "0");
    return 0;
}
