#define all(x) x.begin(), x.end()

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer;
        sort(all(nums1));
        sort(all(nums2));
        int first = 0, second = 0;
        while (first < nums1.size() && second < nums2.size()){
            if (nums1[first] == nums2[second]){
                answer.push_back(nums1[first]);
                first = upper_bound(all(nums1), nums1[first]) - nums1.begin();
                second = upper_bound(all(nums2), nums2[second]) - nums2.begin();
            } else {
                if (nums1[first] < nums2[second]){
                    first++;
                } else {
                    second++;
                }
            }
        }
        return answer;
    }
};