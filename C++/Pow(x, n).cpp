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
    double myPow(double x, int n) {
        long long level = static_cast<long long>(n);
        return level > 0 ? quickPow(x, level) : 1 / quickPow(x, -level);
    }

    double quickPow(double x, long long n) {
        double ret = 1.0;
        while (n) {
            if (n & 1) {
                ret = ret * x;
            }
            x = x * x;
            n >>= 1;
        }
        return ret;
    }
};


int main() {
    Solution solution;
    auto ret = solution.myPow(2.1, 3);
    cout << ret << endl;
    ret = solution.myPow(34.00515, 0);
    cout << ret << endl;
    ret = solution.myPow(34.00515, -3);
    cout << ret << endl;
    ret = solution.myPow(1.00000, 0x8fffffff);
    cout << ret << endl;
    return 0;
}
