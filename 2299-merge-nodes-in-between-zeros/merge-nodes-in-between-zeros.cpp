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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* cur = dummyHead;
        ListNode* walker = head;
        int sum = 0, zeros = 0;
        while (walker){
            if (walker->val != 0){
                sum += walker->val;
            } else {
                zeros++;
                if (zeros == 2){
                    cur->next = new ListNode(sum);
                    cur = cur->next;
                    sum = 0;
                    zeros = 1;
                }
            }
            walker = walker->next;
        }
        return dummyHead->next;

    }
};