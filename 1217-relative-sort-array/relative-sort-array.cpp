class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        sort(arr1.begin(), arr1.end());
        vector<int> answer;
        unordered_map<int, int> dict;
        for (int elem : arr1){
            dict[elem]++;
        }
        for (int i = 0; i < arr2.size(); i++){
            generate_n(back_inserter(answer), dict[arr2[i]], [i, &arr2](){ return arr2[i]; });
            dict.erase(arr2[i]);
        }
        for (int i = 0; i < arr1.size(); i++){
            if (dict.contains(arr1[i])){
                generate_n(back_inserter(answer), dict[arr1[i]], [i, &arr1](){ return arr1[i]; });
                dict.erase(arr1[i]);
            }
        }
        return answer;
        //Я видел как оно набрало 100% по времени, хочу сохранить этот результат на гите ПОПЫТКА 1
    }
};