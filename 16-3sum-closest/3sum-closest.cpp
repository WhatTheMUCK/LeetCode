class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        unordered_set<int> uno, duo;
        uno.insert(nums[0]);
        uno.insert(nums[1]);
        duo.insert(nums[0] + nums[1]);
        int closest = INT_MAX;
        int answer;
        for (int i = 2; i < nums.size(); i++){
            for (int elem : duo){
                int temp = elem + nums[i];
                if (abs(target - temp) < closest){
                    closest = abs(target - temp);
                    answer = temp;
                }
            }
            for (int elem : uno){
                duo.insert(elem + nums[i]);
            }
            uno.insert(nums[i]);
        }
        return answer;
    }
};