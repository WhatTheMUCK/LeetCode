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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st, helper;
        while(head){
            st.push(head);
            head = head->next;
        }
        int maxVal = 0;
        while(!st.empty()){
            if ((st.top())->val >= maxVal){
                maxVal = st.top()->val;
                helper.push(st.top());
            }
            st.pop();
        }
        ListNode* dummyHead = new ListNode(-1), *cur = dummyHead;
        while(!helper.empty()){
            cur->next = helper.top();
            cur = cur->next;
            helper.pop();
        }
        return dummyHead->next;
    }
};