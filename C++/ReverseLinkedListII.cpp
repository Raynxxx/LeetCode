//
// Reverse Linked List II
// Created by Rayn on 2016/10/3.
//
#include <map>
#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* preOfM;
        ListNode* pre = &dummy;
        ListNode* cur = head;
        for (int i = 1; i <= n; ++i) {
            if (i == m) preOfM = pre;
            if (i > m && i <= n) {
                pre->next = cur->next;
                cur->next = preOfM->next;
                preOfM->next = cur;
                cur = pre;
            }
            pre = cur;
            cur = cur->next;
        }
        return dummy.next;
    }
};

int main() {
    Solution solution;
    return 0;
}

