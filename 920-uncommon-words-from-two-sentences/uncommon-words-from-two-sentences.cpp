class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> words1, words2;
        stringstream ss1(s1), ss2(s2);
        string word;
        while (ss1 >> word)
            words1[word]++;
        while (ss2 >> word)
            words2[word]++;
        vector<string> answer;
        for (pair<string, int> elem : words1){
            word = elem.first;
            if (elem.second == 1 && !words2.contains(word))
                answer.push_back(word);
        }
        for (pair<string, int> elem : words2){
            word = elem.first;
            if (elem.second == 1 && !words1.contains(word))
                answer.push_back(word);
        }
        return answer;
    }
};