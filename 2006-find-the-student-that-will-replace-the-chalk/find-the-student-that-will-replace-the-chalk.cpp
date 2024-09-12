class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long cicle = accumulate(chalk.begin(), chalk.end(), 0ll);
        k %= cicle;
        int n = chalk.size();
        int i = 0;
        for (i; i < n && k >= chalk[i]; i++)
            k -= chalk[i];
        return i;
    }
};