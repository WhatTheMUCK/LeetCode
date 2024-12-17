class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> count;
        for (char letter : s){
            count[letter]++;
        }

        priority_queue<pair<char, int>, vector<pair<char, int>>, less<pair<char, int>>> pq;
        for (pair<char, int> elem : count){
            pq.push(elem);
        }
        
        string answer = "@";

        int inARow = 1;
        while (!pq.empty()){
            auto [letter, amount] = pq.top();
            pq.pop();

            if (answer.back() == letter){
                inARow++;
            } else {
                inARow = 1;
            }

            if (inARow <= repeatLimit){
                answer.push_back(letter);
                if (amount - 1 > 0){
                    pq.push({letter, amount - 1});
                }
            } else if (!pq.empty()) {
                auto [letter2, amount2] = pq.top();
                pq.pop();
                answer.push_back(letter2);
                if (amount2 - 1 > 0){
                    pq.push({letter2, amount2 - 1});
                }
                pq.push({letter, amount});
            }
        }

        return answer.substr(1);

    }
};