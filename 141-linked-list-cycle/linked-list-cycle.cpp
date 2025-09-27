/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) {
            return false;
        }

        ListNode * cur = head;
        ListNode * prev = head;
        while (cur && cur->next) {
            cur = cur->next->next;
            prev = prev->next;
            if (cur && prev && cur == prev) {
                return true;
            }
        }

        return false;
    }
};