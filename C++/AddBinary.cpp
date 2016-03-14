#include <map>
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        int i = a.length() - 1, j = b.length() - 1;
        int carry = 0;
        while (i >= 0 && j >= 0) {
            int cur = a[i] - '0' + b[j] - '0' + carry;
            carry = cur / 2;
            cur = cur % 2;
            ret = char(cur + '0') + ret;
            --i, --j;
        }
        while (i >= 0) {
            int cur = a[i] - '0' + carry;
            carry = cur / 2;
            cur = cur % 2;
            ret = char(cur + '0') + ret;
            --i;
        }
        while (j >= 0) {
            int cur = b[j] - '0' + carry;
            carry = cur / 2;
            cur = cur % 2;
            ret = char(cur + '0') + ret;
            --i;
        }
        if (carry > 0) {
            ret = char(carry + '0') + ret;
        }
        return ret;
    }
};


int main() {
    Solution solution;
    auto ret = solution.addBinary("11", "1");
    assert(ret == "100");
    return 0;
}