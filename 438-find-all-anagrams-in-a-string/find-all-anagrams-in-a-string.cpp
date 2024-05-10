class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> anagram , dict;
        for (char elem : p){
            if (anagram.find(elem) != anagram.end()){
                anagram[elem]++;
            } else {
                anagram[elem] = 1;
            }
        }
        int total = p.size();
        dict = anagram;
        int l = 0, r = 0;
        vector<int> answer;
        while (l < s.size() && r < s.size()){
            if (anagram.find(s[r]) == anagram.end()){
                dict = anagram;
                total = p.size();
                l = r + 1;
                r = l;
            } else {
                if (dict[s[r]] == 0){
                    dict[s[l]]++;
                    l++;
                    total++;
                } else {
                    dict[s[r]]--;
                    total--;
                    r++;
                }
            }
            if (total == 0){
                answer.push_back(l);
            }

        }
        return answer;
    }
};