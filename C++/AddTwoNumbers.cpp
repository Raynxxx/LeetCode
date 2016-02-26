#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
/**
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int last = 0;
        list<int> save;
        for (; l1 != NULL && l2 != NULL; l1 = l1->next, l2 = l2->next) {
            int sum = l1->val + l2->val + last;
            last = sum / 10;
            sum = sum % 10;
            save.push_back(sum);
        }
        while (l1 != NULL) {
            int sum = l1->val + last;
            last = sum / 10;
            sum = sum % 10;
            save.push_back(sum);
            l1 = l1->next;
        }
        while (l2 != NULL) {
            int sum = l2->val + last;
            last = sum / 10;
            sum = sum % 10;
            save.push_back(sum);
            l2 = l2->next;
        }
        if (last != 0) {
            save.push_back(last);
        }
        ListNode *head = NULL, *cur = NULL, *prev = NULL;
        while (!save.empty()) {
            cur = new ListNode(save.front());
            save.pop_front();
            if (head == NULL) {
                head = prev = cur;
            } else {
                prev->next = cur;
                prev = cur;
            }
        }
        return head;
    }
};

int main() {
    Solution solution;
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(6);

    ListNode* ret = solution.addTwoNumbers(l1, l2);
    while (ret != NULL) {
        cout << ret->val << endl;
        ret = ret->next;
    }
    return 0;
}