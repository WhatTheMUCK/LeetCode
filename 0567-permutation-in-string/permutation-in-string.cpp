class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;
        unordered_map<char, int> mp, temp;
        for (char elem : s1){
            mp[elem]++;
        }
        temp = mp;
        int helper = s1.size();
        int l = 0, r = 0;
        while (r < s2.size()){
            if (!temp.contains(s2[r])){
                helper = s1.size();
                temp = mp;
                l = r + 1;
            } else {
                while (temp[s2[r]] == 0){
                    temp[s2[l]]++;
                    l++;
                    helper++;
                }
                temp[s2[r]]--;
                helper--;
                if (helper == 0)
                    return true;
            }
            r++;
        }
        return false;
    }
};