class Solution {
public:
    int minimumDeletions(string s) {
        s.push_back('b');
        int consecutiveA = 0, consecutiveB = 0, deletedA = 0;
        int n = s.size(), answer = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == 'b'){
                if (consecutiveB <= consecutiveA + deletedA){
                    answer += consecutiveB - deletedA;
                    consecutiveB = 0;
                    deletedA = 0;
                } else {
                    answer += consecutiveA;
                    deletedA += consecutiveA;
                }
                consecutiveA = 0;
                consecutiveB++;
            } else 
                consecutiveA++;
        }
        return answer;
    }
};