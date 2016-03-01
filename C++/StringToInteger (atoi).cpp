#include <array>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    void myTrim(string& str) {
        str = str.erase(0, str.find_first_not_of(" \t\n\r"));
        str = str.erase(str.find_last_not_of(" \t\n\r") + 1);
    }

    int myAtoi(string str) {
        const int max_int = 0x7fffffff;
        const int min_int = 0x80000000;
        
        myTrim(str);
        int length = str.length();
        long long ret = 0;
        bool negative = false;
        if (length == 0) {
            return 0;
        }
        int i = 0;
        if (str[0] == '-') {
            i = 1;
            negative = true;
        }
        if (str[0] == '+') {
            i = 1;
        }
        for (; i < length; ++i) {
            if (str[i] < '0' || str[i] > '9') {
                break;
            }
            ret = ret * 10 + (str[i] - '0');
            if (ret < min_int || ret > max_int) {
                return negative ? min_int : max_int;
            }
        }
        return int(negative ? -ret : ret);
    }
};

int main() {
    Solution solution;
    auto ret = solution.myAtoi("335");
    assert(ret == 335);
    ret = solution.myAtoi("-5");
    assert(ret == -5);
    ret = solution.myAtoi("+1");
    assert(ret == 1);
    ret = solution.myAtoi("-2147483649");
    assert(ret == 0x80000000);
    ret = solution.myAtoi("2147483648");
    assert(ret == 2147483647);
    ret = solution.myAtoi("");
    assert(ret == 0);
    ret = solution.myAtoi("abc");
    assert(ret == 0);
    ret = solution.myAtoi(" 010");
    assert(ret == 10);
    ret = solution.myAtoi("     +004500");
    assert(ret == 4500);
    ret = solution.myAtoi("  -0012a42");
    assert(ret == -12);
    ret = solution.myAtoi("   +0 123");
    assert(ret == 0);
    return 0;
}