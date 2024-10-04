class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        double costOfTeam = accumulate(skill.begin(), skill.end(), 0) * 2.0 / n;
        if (ceil(costOfTeam) != costOfTeam)
            return -1;
        int cost = (int)costOfTeam;
        long long answer = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++){
            int searchSkill = cost - skill[i];
            if (mp.contains(searchSkill) && mp[searchSkill] > 0){
                answer += 1ll * searchSkill * skill[i];
                mp[searchSkill]--;
            } else {
                mp[skill[i]]++;
            }
        }
        if (accumulate(mp.begin(), mp.end(), 0, [](int acc, const pair<int, int> &x){ return acc + x.second; }))
            return -1;
        return answer;
    }
};