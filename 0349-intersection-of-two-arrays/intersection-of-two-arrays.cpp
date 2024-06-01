#define all(x) x.begin(), x.end()

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(all(nums1)), set2(all(nums2));
        vector<int> answer;
        for (int elem : set2){
            if (set1.contains(elem))
                answer.push_back(elem);
        }
        return answer;
    }
};