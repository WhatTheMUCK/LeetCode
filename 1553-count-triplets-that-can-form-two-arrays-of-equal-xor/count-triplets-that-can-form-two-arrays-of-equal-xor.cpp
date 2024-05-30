class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int answer, tempA, a, b;
        answer = tempA = a = b = 0;
        for (int i = 0; i < arr.size() - 1; i++){
            a ^= arr[i];
            b = 0;
            for (int j = i + 1; j < arr.size(); j++){
                b ^= arr[j];
                answer += a == b;
                tempA = a;
                for (int z = 0; z < i; z++){
                    tempA ^= arr[z];
                    answer += tempA == b;
                }
            }
        }
        return answer;
    }
};