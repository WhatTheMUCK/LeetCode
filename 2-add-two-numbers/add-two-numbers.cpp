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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummyHead = new ListNode(-1);
        ListNode *cur = dummyHead;
        int sum = 0, first, second;
        while (l1 || l2 || sum){
            first = (l1 ? l1->val : 0);
            second = (l2 ? l2->val : 0);
            sum += first + second;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            sum /= 10;
            l1 = (l1 ? l1->next : l1);
            l2 = (l2 ? l2->next : l2);
        }
        return dummyHead->next;
    }
};