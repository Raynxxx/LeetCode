//
// Partition List
// Created by Rayn on 2016/10/3.
//
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) return head;
        ListNode* cur = head;
        ListNode* small_head, *small_tail;
        ListNode* large_head, *large_tail;
        small_head = small_tail = new ListNode(0);
        large_head = large_tail = new ListNode(0);
        while (cur != NULL) {
            if (cur->val < x) {
                small_tail->next = cur;
                small_tail = small_tail->next;
                cur = cur->next;
                small_tail->next = NULL;
            } else {
                large_tail->next = cur;
                large_tail = large_tail->next;
                cur = cur->next;
                large_tail->next = NULL;
            }
        }
        small_tail->next = large_head->next;
        ListNode* ret = small_head->next;
        delete small_head;
        delete large_head;
        return ret;
    }
};

int main() {
    Solution solution;
    return 0;
}

