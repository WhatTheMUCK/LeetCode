class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> dict;
        for (char elem : s){
            dict[elem]++;
        }

        int l = 0, r = 1;
        unordered_map<char, int> temp;
        int total = dict[s[l]] - 1;
        temp[s[l]] = total;
        vector<int> answer;
        while (l < s.size()){
            if (total == 0){
                answer.push_back(r - l);
                l = r;
                r = l + 1;
                temp[s[l]] = dict[s[l]] - 1;
                total += temp[s[l]];
            } else {
                if (temp.find(s[r]) == temp.end()){
                    temp[s[r]] = dict[s[r]] - 1;
                    total += temp[s[r]]; 
                } else {
                    temp[s[r]]--;
                    total--;
                }
                r++;
            }
        }
        return answer;
    }
};