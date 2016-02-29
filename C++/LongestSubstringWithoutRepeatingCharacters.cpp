#include <array>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1);
        int length = s.length();
        int start = -1, ret = 0;
        for (int i = 0; i < length; ++i) {
            char ch = s[i];
            if (hash[ch] > start) {
                start = hash[ch];
            }
            ret = max(ret, i - start);
            hash[ch] = i;
        }
        return ret;
    }
};

int main() {
    Solution solution;
    auto ret = solution.lengthOfLongestSubstring("abcabcbb");
    cout << ret << endl;
    ret = solution.lengthOfLongestSubstring("bbbbb");
    cout << ret << endl;
    ret = solution.lengthOfLongestSubstring("abba");
    cout << ret << endl;
    return 0;
}