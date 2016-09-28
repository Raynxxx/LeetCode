//
// Simplify Path
// Created by Rayn on 16/9/27.
//
#include <map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int length = (int) path.length();
        string cur;
        vector<string> box;
        for (int i = 0; i < length; ++i) {
            if (path[i] != '/') {
                cur += path[i];
            }
            if (path[i] == '/' || i == length - 1) {
                if (cur == "..") {
                    if (box.size() > 0) box.pop_back();
                } else if (cur != "." && cur.length() > 0) {
                    box.push_back(cur);
                }
                cur.clear();
            }
        }
        string ret = "/";
        for (int i = 0; i < box.size(); ++i) {
            ret += box[i];
            if (i != box.size() - 1) {
                ret += '/';
            }
        }
        return ret;
    }
};

int main() {
    Solution solution;
    cout << solution.simplifyPath("/home/") << endl;
    cout << solution.simplifyPath("/a/./b/../../c/") << endl;
    cout << solution.simplifyPath("/../") << endl;
    cout << solution.simplifyPath("/home//foo/") << endl;
    cout << solution.simplifyPath("/...") << endl;
    return 0;
}
