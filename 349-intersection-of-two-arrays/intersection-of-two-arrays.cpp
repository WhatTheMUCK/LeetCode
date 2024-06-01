#define all(x) x.begin(), x.end()

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1(all(nums1)), set2(all(nums2));
        vector<int> answer;
        set_intersection(all(set1), all(set2), back_inserter(answer));
        return answer;
    }
};