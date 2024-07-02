class Solution {
public:
    vector<int> intersect(vector<int>& v1, vector<int>& v2) {
        unordered_map<int, int> nums;
        vector<int> answer;
        for (int elem : v1){
            nums[elem]++;
        }
        for (int elem : v2){
            if (nums[elem] > 0){
                answer.push_back(elem);
            }
            nums[elem]--;
        }
        return answer;
    }  
};