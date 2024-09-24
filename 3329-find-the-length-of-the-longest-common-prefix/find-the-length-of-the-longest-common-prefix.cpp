class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;
        for (int elem : arr1){
            while (elem > 0){
                prefixes.insert(elem);
                elem /= 10;
            }
        }
        int answer = 0;
        for (int elem : arr2){
            while (elem > 0){
                if (prefixes.contains(elem)){
                    answer = max(answer, (int)log10(elem) + 1);
                }
                elem /= 10;
            }
        }
        return answer;
    }
};