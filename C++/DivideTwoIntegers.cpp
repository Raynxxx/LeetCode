#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        const int max_int = 0x7fffffff;
        const int min_int = 0x80000000;
        bool neg = false;
        if (dividend < 0)   neg = !neg;
        if (divisor < 0)    neg = !neg;
        if (divisor == 0)   return max_int;
        long long ret = 0;
        long long a = tabs((long long) dividend);
        long long b = tabs((long long) divisor);
        while (a >= b) {
            long long c = b;
            for (int i = 0; c <= a; i++, c <<= 1) {
                a -= c;
                ret += (long long) 1 << i;
            }
        }
        if (neg) ret = -ret;
        if (ret > max_int || ret < min_int){
            return max_int;
        }
        return (int) ret;
    }

    template <class T>
    T tabs(T val) {
        return val > 0 ? val : -val;
    }
};


int main() {
    Solution solution;
    int ret = solution.divide(56, 7);
    assert(ret == 8);
    ret = solution.divide(-int(2147483648), -int(1));
    assert(ret == 2147483647);
    ret = solution.divide(-int(2147483648), 1);
    assert(ret == -int(2147483648));
    return 0;
}