//
// Gray Code
// Created by Rayn on 2016/10/3.
//
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    string leftPadding(string origin, int length, char ch) {
        size_t diff = length - origin.length();
        if (diff <= 0) return origin;
        origin.insert(0, diff, ch);
        return origin;
    }

    void genGrayCode(int n, vector<string>& box) {
        if (n == 1) {
            box.push_back("0");
            box.push_back("1");
            return;
        }
        genGrayCode(n - 1, box);
        for (int i = (int) (box.size() - 1); i >= 0; --i) {
            box.push_back('1' + leftPadding(box[i], n - 1, '0'));
        }
    }

    int binaryToDecimal(string bin) {
        int ret = 0;
        int multiple = 1;
        for (int i = (int) (bin.length() - 1); i >= 0; --i) {
            ret += (bin[i] - '0') * multiple;
            multiple *= 2;
        }
        return ret;
    }

    vector<int> grayCode(int n) {
        vector<string> box;
        vector<int> code;
        if (n == 0) {
            code.push_back(0);
            return code;
        }
        genGrayCode(n, box);
        for (int i = 0; i < box.size(); ++i) {
            cout << box[i] << " ";
            code.push_back(binaryToDecimal(box[i]));
        }
        cout << endl;
        return code;
    }
};

int main() {
    Solution solution;
    solution.grayCode(3);
    return 0;
}
