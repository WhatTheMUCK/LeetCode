class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        sort(arr1.begin(), arr1.end());
        vector<int> answer, visited(arr1.size(), 0);
        for (int i = 0; i < arr2.size(); i++){
            vector<int>::iterator l = lower_bound(arr1.begin(), arr1.end(), arr2[i]);
            vector<int>::iterator r = upper_bound(arr1.begin(), arr1.end(), arr2[i]);
            generate_n(back_inserter(answer), r - l, [i, &arr2](){ return arr2[i]; });
            for (int i = l - arr1.begin(); i < r - arr1.begin(); i++){
                visited[i] = 1;
            }
        }

        for (int i = 0; i < arr1.size(); i++){
            if (!visited[i])
                answer.push_back(arr1[i]);
        }
        return answer;
    }
};