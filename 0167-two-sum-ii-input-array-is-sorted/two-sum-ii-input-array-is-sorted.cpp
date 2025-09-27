#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        std::unordered_map<int, int> mp;
        int n = static_cast<int>(numbers.size());
        for (int i = 0; i < n; ++i) {
            int cur = numbers[i];
            if (mp.contains(target - cur)) {
                return {mp[target - cur], i + 1};
            }
            mp[cur] = i + 1;
        }

        return {-1, -1};
    }
};