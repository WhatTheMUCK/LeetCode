class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> dict;
        for (string& elem : arr){
            dict[elem]++;
        }

        int steps = k;
        for (string& elem : arr){
            if (dict[elem] == 1){
                steps--;
                if (steps == 0)
                    return elem;
            }
        }

        return "";

    }
};