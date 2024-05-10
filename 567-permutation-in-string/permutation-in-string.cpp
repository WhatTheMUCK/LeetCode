class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> first, temp;
        for (char elem : s1){
            first[elem]++;
        }

        temp = first;
        int l = 0, r = 0, total = s1.size();
        while (l < s2.size()){
            if (temp.find(s2[r]) != temp.end()){
                if (temp[s2[r]] > 0){
                    temp[s2[r]]--;
                    total--;
                    r++;
                } else {
                    if (temp.find(s2[l]) != temp.end())
                        temp[s2[l]]++;
                    l++;
                    total++;
                }
            } else {
                l = r + 1;
                r = l;
                temp = first;
                total = s1.size();
            }
            if (total == 0){
                return true;
            }
        }
        return false;
    }
};