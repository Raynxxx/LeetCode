#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        vector<int> factor(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            nums.push_back(i);
            factor[i] = factor[i - 1] * i;
        }
        string ret;
        for (int i = n - 1; i >= 0; --i) {
            int curIndex = (k - 1) / factor[i];
            k = k - curIndex * factor[i];
            ret += char(nums[curIndex] + '0');
            nums.erase(nums.begin() + curIndex);
        }
        return ret;
    }
};

int main() {
    Solution solution;
    auto ret = solution.getPermutation(8, 8590);
    cout << ret << endl;
    return 0;
}
