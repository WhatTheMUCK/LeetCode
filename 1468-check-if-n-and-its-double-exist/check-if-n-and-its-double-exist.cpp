class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> set;
        set.insert(arr[0]);
        int n = arr.size();
        for (int i = 1; i < n; i++){
            int curNum = arr[i];
            if (curNum % 2 == 0 && set.contains(curNum / 2) || set.contains(curNum * 2))
                return true;
            set.insert(curNum);
        }
        return false;
    }
};