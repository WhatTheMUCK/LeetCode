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
        int sum = 0, val1, val2;
        ListNode* dummyHead = new ListNode(-1);
        ListNode* cur = dummyHead;
        while (l1 || l2){
            val1 = l1 == nullptr ? 0 : l1->val;
            val2 = l2 == nullptr ? 0 : l2->val;
            sum += val1 + val2;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            sum /= 10;
            l1 = l1 == nullptr ? l1 : l1->next; 
            l2 = l2 == nullptr ? l2 : l2->next; 
        }
        if (sum)
            cur->next = new ListNode(sum);
        return dummyHead->next;
    }
};