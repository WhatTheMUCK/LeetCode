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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode *dummyHead = new ListNode(-1);
        ListNode *cur = dummyHead;
        sort(nums.begin(), nums.end());
        while (head){
            vector<int>::iterator binarySearch = lower_bound(nums.begin(), nums.end(), head->val);
            if (binarySearch == nums.end() || *binarySearch != head->val){
                cur->next = new ListNode(head->val);
                cur = cur->next;
            }
            head = head->next;
        }
        return dummyHead->next;
    }
};