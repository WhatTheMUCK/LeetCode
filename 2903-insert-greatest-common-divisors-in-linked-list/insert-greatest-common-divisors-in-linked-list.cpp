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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode *incoming = head->next;
        while (incoming){
            head->next = new ListNode(gcd(head->val, incoming->val));
            head = head->next;
            head->next = incoming;
            head = head->next;
            incoming = incoming->next;
        }
        return dummyHead->next;
    }
};