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
        ListNode *fast = head, *slow = head;
        if (!fast || !fast->next)
            return false;
        fast = fast->next->next;
        slow = slow->next;
        while (fast && fast->next && slow){
            if (fast == slow)
                return true;
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};