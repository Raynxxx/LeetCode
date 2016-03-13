#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = s.length();
        int lastWord = -1;
        for (int i = length - 1; i >= 0; --i) {
            if (s[i] != ' ' && lastWord == -1) {
                lastWord = i;
                break;
            }
        }
        int ret = 0;
        if (lastWord != -1) {
            while (lastWord >= 0 && s[lastWord--] != ' ') {
                ret++;
            }
        }
        return ret;
    }
};


int main() {
    Solution solution;
    auto ret = solution.lengthOfLastWord("Hello World");
    assert(ret == 5);
    ret = solution.lengthOfLastWord("tklYjD");
    assert(ret == 6);
    return 0;
}