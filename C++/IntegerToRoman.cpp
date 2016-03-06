#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        static string roman[4][10] = {
            { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
            { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
            { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },
            { "", "M", "MM", "MMM" }
        };
        string ret = "";
        int index = 0;
        while (num != 0) {
            int mod = num % 10;
            num /= 10;
            ret = roman[index][mod] + ret;
            index++;
        }
        return ret;
    }
};

int main() {
    Solution solution;
    string ret;
    ret = solution.intToRoman(1);
    assert(ret == "I");
    ret = solution.intToRoman(19);
    assert(ret == "XIX");
    return 0;
}