class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> mp;
        for (int i = 0; i < s.size(); i++){
            if (!mp.contains(s[i])){
                mp[s[i]] = {1, i};
            } else {
                mp[s[i]].first++;
            }
        }
        vector<pair<int, int>> helper;
        for (auto elem : mp){
            helper.push_back(elem.second);
        }
        sort(helper.begin(), helper.end());
        if (helper[0].first == 1)
            return helper[0].second;
        return -1;
    }
};