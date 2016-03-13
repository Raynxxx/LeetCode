#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int size = digits.size();
        vector<int> ret(size);
        for (int i = size - 1; i >= 0; --i) {
            int cur = digits[i] + carry;
            carry = cur / 10;
            ret[i] = cur % 10;
        }
        if (carry > 0) {
            ret.insert(ret.begin(), 1);
        }
        return ret;
    }
};


int main() {
    Solution solution;
    vector<int> digits = { 9, 9, 8 };
    auto ret = solution.plusOne(digits);
    for (int i = 0; i < ret.size(); ++i) {
        cout << ret[i];
    }
    return 0;
}