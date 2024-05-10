class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> first;
        for (int elem : nums1){
            if (first.find(elem) != first.end()){
                first[elem]++;
            } else {
                first[elem] = 1;
            }
        }

        vector<int> answer;
        for (int elem : nums2){
            if (first.find(elem) != first.end() && first[elem] > 0){
                answer.push_back(elem);
                first[elem]--;
            }
        }

        return answer;
    }
};