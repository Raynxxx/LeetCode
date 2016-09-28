//
// Sort Colors
// Created by Rayn on 16/9/28.
//
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = -1, white = -1, blue = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                nums[++blue] = 2;
                nums[++white] = 1;
                nums[++red] = 0;
            } else if (nums[i] == 1) {
                nums[++blue] = 2;
                nums[++white] = 1;
            } else {
                nums[++blue] = 2;
            }
        }
    }
};

int main() {
    return 0;
}

