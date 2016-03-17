#include <map>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    Solution(): dict()
    {
        initDict();
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        getCombinations("", 0, digits, ret);
        return ret;
    }

private:
    map<char, string> dict;

    void initDict() {
        dict.clear();
        dict.insert({ '2', "abc" });
        dict.insert({ '3', "def" });
        dict.insert({ '4', "ghi" });
        dict.insert({ '5', "jkl" });
        dict.insert({ '6', "mno" });
        dict.insert({ '7', "pqrs" });
        dict.insert({ '8', "tuv" });
        dict.insert({ '9', "wxyz" });
    }

    void getCombinations(string combination, int dep, const string& digits, vector<string>& ret) {
        if (dep == digits.size() && !combination.empty()) {
            ret.push_back(combination);
            return;
        }
        int digit = digits[dep];
        for (int i = 0; i != dict[digit].length(); ++i) {
            getCombinations(combination + dict[digit][i], dep + 1, digits, ret);
        }
    }

};


int main() {
    Solution solution;
    auto ret = solution.letterCombinations("12");
    for (auto& s : ret) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}
