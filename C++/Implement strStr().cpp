#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        int index = -1;
        for (int i = 0; i != haystack.length(); ++i) {
            if (needle == haystack.substr(i, needle.length())) {
                index = i;
                break;
            }
        }
        return index;
    }
};

int main() {
    Solution solution;
    auto ret = solution.strStr("hello world", "world");
    assert(ret == 6);
    ret = solution.strStr("", "");
    assert(ret == 0);
    return 0;
}