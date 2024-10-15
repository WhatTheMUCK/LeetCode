class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size(), l = n - 1, r = n - 1;
        long long answer = 0;
        while (r > 0){
            if (l > r)
                l = r;
            while (l >= 0 && s[l] != '1')
                l--;
            if (l < 0)
                break;
            answer += r - l;
            if (l != r)
                swap(s[r], s[l]);
            r--;
        }
        return answer;
    }
};