class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> dict;
        for (char elem : magazine){
            if (dict.find(elem) != dict.end()){
                dict[elem]++;
            } else {
                dict[elem] = 1;
            }
        }
        for (char elem : ransomNote){
            if (dict.find(elem) ==  dict.end()){
                return false;
            }
            if (dict[elem] == 0){
                return false;
            }
            dict[elem]--;
        }
        return true;
    }
};