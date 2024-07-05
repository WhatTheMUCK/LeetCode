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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *prev = head, *cur = head->next, *nextt = head->next->next;
        int firstCriticalInd = -1, lastCriticalInd = -1, minDistance = INT_MAX, maxDistance = INT_MIN, i = 0;
        while (nextt){
            if (prev->val < cur->val && cur->val > nextt->val || prev->val > cur->val && cur->val < nextt->val){
                if (firstCriticalInd == -1)
                    firstCriticalInd = i;
                if (lastCriticalInd != -1){
                    minDistance = min(minDistance, i - lastCriticalInd);
                    maxDistance = max(maxDistance, i - firstCriticalInd);
                }
                lastCriticalInd = i;
            }
            i++;
            prev = prev->next;
            cur = cur->next;
            nextt = nextt->next;
        }
        if (minDistance != INT_MAX && maxDistance != INT_MIN){
            return {minDistance, maxDistance};
        }
        return {-1, -1};
    }
};