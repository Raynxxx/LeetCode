#include <array>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int digits[20], len = 0;
        while (x != 0) {
            digits[len++] = x % 10;
            x = x / 10;
        }
        for (int i = 0; i < (len + 1) / 2; ++i) {
            if (digits[i] != digits[len - i - 1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    bool ret;
    ret = solution.isPalindrome(-5);
    assert(!ret);
    ret = solution.isPalindrome(121);
    assert(ret);
    ret = solution.isPalindrome(1221);
    assert(ret);
    ret = solution.isPalindrome(12251);
    assert(!ret);
    return 0;
}