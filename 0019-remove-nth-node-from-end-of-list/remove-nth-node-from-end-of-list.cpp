 /*
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode *cur = dummyHead, *helper = dummyHead;
        for (int i = 0; i <= n; i++){
            helper = helper->next;
        }
        while (helper){
            helper = helper->next;
            cur = cur->next;
        }
        cur->next = cur->next->next;
        return dummyHead->next;
    }
};