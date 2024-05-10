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
    ListNode* reversedList(ListNode* head){
        ListNode *prev = nullptr, *cur = head, *nextNode;
        while(cur){
            nextNode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextNode;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        int sum = 0;
        ListNode *start = reversedList(head), *node = start, *prev;
        while(node){
            sum += node->val * 2;
            node->val = sum % 10;
            sum /= 10;
            prev = node;
            node = node->next;
        }
        if (sum){
            prev->next = new ListNode(sum);
        }
        ListNode *answer = reversedList(start);
        return answer;
    }
};