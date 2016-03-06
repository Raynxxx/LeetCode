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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < n - 1; ++i) {
            if (fast->next != NULL) {
                fast = fast->next;
            }
        }
        ListNode* prev = NULL;
        while (fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if (prev == NULL) {
            head = slow->next;
            delete slow;
        } else {
            prev->next = slow->next;
            delete slow;
        }
        return head;
    }
};

int main() {
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode* ret = solution.removeNthFromEnd(head, 2);

    return 0;
}