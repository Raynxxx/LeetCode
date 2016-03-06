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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        ListNode *ret = NULL, *prev = NULL;
        while (l1 != NULL && l2 != NULL) {
            if (ret == NULL) {
                if (l1->val < l2->val) {
                    ret = prev = l1;
                    l1 = l1->next;
                } else {
                    ret = prev = l2;
                    l2 = l2->next;
                }
            } else {
                if (l1->val < l2->val) {
                    prev->next = l1;
                    prev = prev->next;
                    l1 = l1->next;
                } else {
                    prev->next = l2;
                    prev = prev->next;
                    l2 = l2->next;
                }
            }
        }
        if (l1 != NULL) {
            prev->next = l1;
        } else if (l2 != NULL) {
            prev->next = l2;
        }
        return ret;
    }
};

int main() {
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(5);
    head->next->next->next = new ListNode(7);
    head->next->next->next->next = new ListNode(9);
    ListNode* head2 = new ListNode(0);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(4);
    head2->next->next->next = new ListNode(6);
    head2->next->next->next->next = new ListNode(8);
    ListNode* ret = solution.mergeTwoLists(head, head2);
    while (ret != NULL) {
        cout << ret->val << endl;
        ret = ret->next;
    }
    return 0;
}