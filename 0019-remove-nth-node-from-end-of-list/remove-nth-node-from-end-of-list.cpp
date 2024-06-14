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
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *helper = dummy;
        ListNode *walker = dummy;
        for (int i = 0; i <= n; i++){
            walker = walker->next;
        }
        while (walker){
            walker = walker->next;
            helper = helper->next;
        }
        helper->next = helper->next->next;
        return dummy->next;
    }
};