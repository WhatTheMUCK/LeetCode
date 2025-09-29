class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() < nums2.size()) {
            return intersect(nums2, nums1);
        }

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> answer;
        size_t firstInd = 0, secondInd = 0;
        while (firstInd < nums1.size() && secondInd < nums2.size()) {
            if (nums1[firstInd] == nums2[secondInd]) {
                answer.push_back(nums1[firstInd]);
                ++firstInd, ++ secondInd;
                continue;
            }

            if (nums1[firstInd] < nums2[secondInd]) {
                ++firstInd;
                continue;
            }

            if (nums1[firstInd] > nums2[secondInd]) {
                ++secondInd;
                continue;
            }
        }
        return answer;
    }
};