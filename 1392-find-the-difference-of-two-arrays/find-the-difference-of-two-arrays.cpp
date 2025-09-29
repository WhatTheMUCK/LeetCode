class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1(nums1.begin(), nums1.end()), st2(nums2.begin(), nums2.end());
        vector<vector<int>> answer(2);
        for (int elem : st1) {
            if (!st2.contains(elem)) {
                answer[0].push_back(elem);
            }
        }

        for (int elem : st2) {
            if (!st1.contains(elem)) {
                answer[1].push_back(elem);
            }
        }

        return answer;
    }
};