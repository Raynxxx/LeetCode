#include <array>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> ret(numRows);
        int gap = numRows - 2;
        int length = s.length();
        for (int i = 0; i < length;) {
            for (int j = 0; i < length && j < numRows; ++j) {
                ret[j] += s[i++];
            }
            for (int j = gap; i < length && j > 0; --j) {
                ret[j] += s[i++];
            }
        }
        string result = "";
        for (int i = 0; i < numRows; ++i) {
            result += ret[i];
        }
        return result;
    }
};

int main() {
    Solution solution;
    auto ret = solution.convert("PAYPALISHIRING", 3);
    cout << ret << endl;
    return 0;
}