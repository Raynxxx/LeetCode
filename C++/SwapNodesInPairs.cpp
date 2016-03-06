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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode *p1 = head, *p2 = head->next;
        ListNode *ret = NULL, *prev = NULL;
        while (p1 && p2) {
            p1->next = p2->next;
            p2->next = p1;
            if (ret == NULL) {
                ret = p2;
            }
            if (prev != NULL) {
                prev->next = p2;
            }
            prev = p1;
            if (p1) p1 = p1->next;
            if (p1) p2 = p1->next;
        }
        if (ret == NULL) {
            ret = head;
        }
        return ret;
    }
};


int main() {
    Solution solution;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    solution.swapPairs(head);
    return 0;
}