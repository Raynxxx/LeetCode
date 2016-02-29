#include <array>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        const int max_int = 0x7fffffff;
        const int min_int = 0x80000000;
        long long ret = 0;
        while (x != 0) {
            int cur = x % 10;
            x = x / 10;
            ret = ret * 10 + cur;
            if (ret < min_int || ret > max_int) {
                return 0;
            }
        }
        return (int) ret;
    }
};

int main() {
    Solution solution;
    auto ret = solution.reverse(335);
    cout << ret << endl;
    ret = solution.reverse(-335);
    cout << ret << endl;
    ret = solution.reverse(100);
    cout << ret << endl;
    ret = solution.reverse(-1000);
    cout << ret << endl;
    return 0;
}