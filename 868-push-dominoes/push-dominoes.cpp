class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes.push_back('R');
        int n = dominoes.size();
        string answer = dominoes;
        char lastSeen = 'L';
        int lastIndex = -1;
        for (int i = 0; i < n; i++){
            if (dominoes[i] == '.'){
                continue;
            }
            if (dominoes[i] == lastSeen){
                answer.replace(lastIndex + 1, i - lastIndex, i - lastIndex, dominoes[i]);
            } else if (lastSeen == 'R') {
                int sizeOfGap = ((i - 1) - (lastIndex + 1) + 1) / 2;
                if (sizeOfGap > 0){
                    answer.replace(lastIndex + 1, sizeOfGap, sizeOfGap, lastSeen);
                    answer.replace(i - sizeOfGap, sizeOfGap, sizeOfGap, dominoes[i]);
                }
            }
            lastSeen = dominoes[i];
            lastIndex = i;
        }
        answer.pop_back();
        return answer;
    }
};