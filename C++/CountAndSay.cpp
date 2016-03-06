#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string cur = "1";
        for (int k = 1; k < n; ++k) {
            int i = 0;
            string tmp = "";
            while (i < cur.size()) {
                int p = i + 1, size = 1;
                while (p < cur.size() && cur[p] == cur[i]) {
                    p++, size++;
                }
                tmp += char(size + '0');
                tmp += cur[i];
                i = p;
            }
            cur = tmp;
        }
        return cur;
    }
};


int main() {
    Solution solution;
    cout << solution.countAndSay(1) << endl;
    cout << solution.countAndSay(2) << endl;
    cout << solution.countAndSay(3) << endl;
    cout << solution.countAndSay(4) << endl;
    cout << solution.countAndSay(5) << endl;
    cout << solution.countAndSay(6) << endl;
    return 0;
}