class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        stable_sort(nums.begin(), nums.end(), [&](int l, int r){
            int tempL = l, tempR = r;
            int mappingL = 0, mappingR = 0;
            int pow10 = 1;
            do {
                int digit = tempL % 10;
                mappingL += mapping[digit] * pow10;
                tempL /= 10;
                pow10 *= 10;
            } while (tempL > 0);
            pow10 = 1;
            do {
                int digit = tempR % 10;
                mappingR += mapping[digit] * pow10;
                tempR /= 10;
                pow10 *= 10;
            } while (tempR > 0);
            return mappingL < mappingR;
        });
        return nums;
    }
};