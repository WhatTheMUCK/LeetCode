class Solution {
public:
    int compress(vector<char>& chars) {
        int l = 0, r = 1;
        string answer = "";
        while (l < chars.size()){
            while (r < chars.size() && chars[l] == chars[r]){
                r++;
            }
            answer += chars[l];
            if (r - l > 1){
                answer += to_string(r - l);
            }
            l = r;
        }
        for (int i = 0; i < answer.size(); i++){
            chars[i] = answer[i];
        }
        return answer.size();
    }
};