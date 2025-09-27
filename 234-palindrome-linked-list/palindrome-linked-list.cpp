/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode * copy(ListNode * head) {
        ListNode * dummyHead = new ListNode(-42);
        ListNode * cur1 = dummyHead;
        ListNode * cur2 = head;
        while (cur2) {
            cur1->next = new ListNode(cur2->val);
            cur2 = cur2->next;
            cur1 = cur1->next;
        }

        return dummyHead->next;
    }

    ListNode * reverse(ListNode * head) {
        ListNode * prev = nullptr;
        ListNode * cur = head;
        while (cur) {
            ListNode * next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode * cur1 = copy(head);
        ListNode * cur2 = reverse(head);
        
        while (cur1 && cur2 && cur1->val == cur2->val) {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }

        if (!cur1 && !cur2) {
            return true;
        }

        return false;
    }
};