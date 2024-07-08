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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummyHead = new ListNode(-1);
        ListNode *cur = dummyHead;
        while (list1 && list2){
            int val1 = list1->val, val2 = list2->val;
            if (val1 < val2){
                cur->next = new ListNode(val1);
                cur = cur->next;
                list1 = list1->next;
            } else {
                cur->next = new ListNode(val2);
                cur = cur->next;
                list2 = list2->next;
            }
        }

        while (list1){
            int val1 = list1->val;
            cur->next = new ListNode(val1);
            cur = cur->next;
            list1 = list1->next;
        }

        while (list2){
            int val2 = list2->val;
            cur->next = new ListNode(val2);
            cur = cur->next;
            list2 = list2->next;
        }

        return dummyHead->next;
    }
};