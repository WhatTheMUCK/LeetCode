class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int XOR = 0;
        for (int i = 0; i < nums.size(); i++){
            XOR ^= nums[i];
        } 
        int pos = __builtin_ffs(XOR) - 1; // У __builtin_ffs индексация с 1
        // int pos = 0;
        // for (pos; !(XOR & (1ll << pos)); pos++);
        // Тоже самое что и __builtin_ffs (Встроенный поиск первого установленного бита "builtin find first set")
        int answer1 = 0, answer2 = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] & (1 << pos))
                answer1 ^= nums[i];
            else
                answer2 ^= nums[i];
        }
        return {answer1, answer2};
    }
};