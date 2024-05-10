class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> first(nums1.begin(), nums1.end()), second(nums2.begin(), nums2.end());
        vector<vector<int>> answer(2);
        for (int elem : second){
            if (first.find(elem) == first.end()){
                answer[1].push_back(elem);
            }
        }

        for (int elem : first){
            if (second.find(elem) == second.end()){
                answer[0].push_back(elem);
            }
        }

        return answer;
    }
};