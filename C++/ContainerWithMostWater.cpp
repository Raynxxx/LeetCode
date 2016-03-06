#include <array>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int ret = 0;
        int left = 0, right = size - 1;
        while (left < right) {
            int cur = min(height[left], height[right]) * (right - left);
            if (cur > ret) {
                ret = cur;
            }
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return ret;
    }
};

int main() {
    Solution solution;
    int ret;
    vector<int> height = { 1, 2, 1 };
    ret = solution.maxArea(height);
    assert(ret == 2);
    return 0;
}