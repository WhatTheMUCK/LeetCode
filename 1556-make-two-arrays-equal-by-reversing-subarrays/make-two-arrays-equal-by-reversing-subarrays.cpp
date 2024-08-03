class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> dict;
        for (int elem : target){
            dict[elem]++;
        }
        for (int elem : arr){
            if (!dict.contains(elem) || dict[elem] == 0)
                return false;
            dict[elem]--;
        }
        return true;
    }
};