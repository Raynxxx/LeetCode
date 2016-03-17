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
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        gao("", n, n, ret);
        return ret;
    }

private:
    void gao(string cur, int left, int right, vector<string>& ret) {
        if (left == 0 && right == 0) {
            ret.push_back(cur);
        }
        if (left > 0) {
            gao(cur + '(', left - 1, right, ret);
        }
        if (right > 0 && left < right) {
            gao(cur + ')', left, right - 1, ret);
        }
    }
};


int main() {
    Solution solution;
    auto ret = solution.generateParenthesis(3);
    for (auto& s : ret) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}
