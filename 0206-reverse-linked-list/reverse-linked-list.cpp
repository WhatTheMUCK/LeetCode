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
    ListNode* reverseList(ListNode* head) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* cur = dummyHead->next;
        while (head != nullptr){
            ListNode* temp = new ListNode(head->val);
            dummyHead->next = temp;
            temp->next = cur;
            cur = temp;
            head = head->next;
        }
        return dummyHead->next;
    }
};