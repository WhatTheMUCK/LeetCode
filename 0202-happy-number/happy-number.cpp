class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> was;
        while (n != 1){
            int helper = 0;
            while (n != 0){
                helper += (n % 10) * (n % 10);
                n /= 10; 
            }
            if (was.contains(helper))
                return false;
            was.insert(helper);
            n = helper;
        }
        return true;
    }
};