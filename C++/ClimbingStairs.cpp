#include <map>
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    Solution() : memory() {}

    int climbStairs(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (memory.count(n)) {
            return memory[n];
        }
        memory[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return memory[n];
    }

private:
    unordered_map<int, int> memory;
};


int main() {
    Solution solution;
    auto ret = solution.climbStairs(0);
    assert(ret == 0);
    ret = solution.climbStairs(1);
    assert(ret == 1);
    ret = solution.climbStairs(2);
    assert(ret == 2);
    ret = solution.climbStairs(3);
    assert(ret == 3);
    ret = solution.climbStairs(4);
    assert(ret == 5);
    ret = solution.climbStairs(5);
    assert(ret == 8);
    ret = solution.climbStairs(10);
    assert(ret == 89);
    ret = solution.climbStairs(30);
    assert(ret == 1346269);
    return 0;
}