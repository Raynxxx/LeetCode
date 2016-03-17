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
    bool isValid(string s) {
        static map<char, char> validParentheses = {
            { '(', ')' },
            { '{', '}' },
            { '[', ']' }
        };
        stack<char> box;
        int length = s.length();
        for (int i = 0; i < length; ++i) {
            if (!box.empty() && validParentheses[box.top()] == s[i]) {
                box.pop();
            } else {
                box.push(s[i]);
            }
        }
        return box.empty();
    }
};


int main() {
    Solution solution;
    auto ret = solution.isValid("()");
    assert(ret == true);
    ret = solution.isValid("()[]{}");
    assert(ret == true);
    ret = solution.isValid("([)]");
    assert(ret == false);
    return 0;
}
