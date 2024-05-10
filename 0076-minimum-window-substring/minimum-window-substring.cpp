class Solution {
public:
    string minWindow(string s, string t) {
        string answer = "";
        if (t.size() > s.size())
            return answer;
        unordered_map<char, int> dict;
        for (char elem : t){
            dict[elem]++;
        }
        int minimum = s.size() + 1, index;
        int diff = t.size();
        int l = 0, r = 0;
        while (l < s.size()){
            while (diff > 0 && r < s.size()){
                if (dict.find(s[r]) != dict.end()){
                    dict[s[r]]--;
                    if (dict[s[r]] >= 0)
                        diff--;
                }
                r++;
            }
            if (diff == 0 && r - l < minimum){
                minimum = r - l;
                index = l;
            }
            if (dict.find(s[l]) != dict.end()){
                dict[s[l]]++;
                if (dict[s[l]] > 0)
                    diff++;
            }
            l++;
        }
        return minimum == s.size() + 1 ? "" : s.substr(index, minimum);
    }
};