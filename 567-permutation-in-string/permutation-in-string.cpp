class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size())
            return false;
        unordered_map<char, int> start, dict;
        for (char elem : s1)
            start[elem]++;
        
        dict = start;
        int helper = s1.size();
        int l = 0, r = 0;
        while (r < s2.size()){
            if (!dict.contains(s2[r])){
                dict = start;
                l = r + 1;
                r = l;
                helper = s1.size();
            } else {
                if (dict[s2[r]] > 0){
                    dict[s2[r]]--;
                    r++;
                    helper--;
                } else {
                    dict[s2[l]]++;
                    l++;
                    helper++;
                }
            }
            if (!helper)
                return true;
        } 
        return false;
    }
};