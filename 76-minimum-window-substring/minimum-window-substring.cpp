class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> dict;
        for (char elem : t){
            dict[elem]++;
        }
        int checker = t.size();
        int l = 0, r = 0, minSize = INT_MAX, startIndex = -1;
        while (l < s.size()){
            if (r < s.size() && checker > 0){
                if (dict[s[r]] > 0)
                    checker--;
                dict[s[r]]--;
                r++;
            } else {
                if (checker == 0){
                    if (r - l < minSize){
                        minSize = r - l;
                        startIndex = l;
                    }
                }
                if (dict[s[l]] == 0)
                    checker++;
                dict[s[l]]++;
                l++;
            }
        }
        if (startIndex == -1)
            return "";
        return s.substr(startIndex, minSize);
    }
};