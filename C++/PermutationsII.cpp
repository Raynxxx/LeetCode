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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        do {
            ret.push_back(nums);
        } while (nextPermutation(nums));
        return ret;
    }

private:
    bool nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return false;

        int i = size - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i < 0) {
            return false;
        }
        int j = size - 1;
        while (j > i && nums[j] <= nums[i]) {
            j--;
        }
        swap(nums[i], nums[j]);

        int left = i + 1, right = size - 1;
        while (left < right) {
            swap(nums[left], nums[right]);
            left++, right--;
        }
        return true;
    }
};


int main() {
    Solution solution;
    vector<int> vec = { 1, 1, 2 };
    auto ret = solution.permuteUnique(vec);
    for (auto& per : ret) {
        copy(per.begin(), per.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
    return 0;
}
