class Solution {
public:
    int minimumPushes(string word) {
        vector<int> dict('z' - 'a' + 1);
        for (char letter : word)
            dict[letter - 'a']++;
        sort(dict.begin(), dict.end(), greater<>());
        int answer = 0;
        int occupied = 0;
        for (int elem : dict){
            answer += (occupied / 8 + 1) * elem;
            occupied++;
        }
        return answer;
    }
};