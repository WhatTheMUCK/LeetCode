class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> dict;
        if (s.size() != t.size()){
            return false;
        }
        for (char elem : s){
            if (dict.find(elem) != dict.end()){
                dict[elem]++;
            } else {
                dict[elem] = 1;
            }
        }

        for (char elem : t){
            if (dict.find(elem) != dict.end() && dict[elem] > 0){
                dict[elem]--;
            } else {
                return false;
            }
        }

        return true;
    }
};