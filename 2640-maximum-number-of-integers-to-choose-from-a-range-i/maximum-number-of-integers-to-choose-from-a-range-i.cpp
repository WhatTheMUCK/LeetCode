class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int answer = 0;
        int i = 1;
        sort(banned.begin(), banned.end());
        banned.push_back(1e9 + 1);
        while (maxSum >= 0 && i <= n){
            while(*lower_bound(banned.begin(), banned.end(), i) == i && i <= n){
                i++;
            }
            if (i > n){
                break;
            }
            maxSum -= i;
            if (maxSum < 0){
                break;
            }
            answer++;
            i++;
        }
        return answer;
    }
};