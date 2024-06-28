class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> letter('z' - 'a' + 1);
        unordered_set<string> used;
        int i = 0;
        stringstream ss(s);
        string temp;
        while (ss >> temp){
            if (i == pattern.size())
                return false;
            if (!letter[pattern[i] - 'a'].empty() && letter[pattern[i] - 'a'] != temp)
                return false;
            if (letter[pattern[i] - 'a'] != temp && used.contains(temp))
                return false;
            letter[pattern[i++] - 'a'] = temp;
            used.insert(temp);
        }
        return i == pattern.size();
    }
};