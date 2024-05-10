class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int> answer(deck.size());
        queue<int> helper;
        sort(deck.begin(), deck.end());
        for (int i = 0; i < deck.size(); i++){
            cout << deck[i] << " ";
            helper.push(i);
        }
        //cout << "\n";
        int top, gone, i = 0;
        while (!helper.empty()){
            top = helper.front();
            //cout << top;
            helper.pop();
            answer[top] = deck[i++];
            if (!helper.empty()){
                gone = helper.front();
                //cout << " " << gone << "\n";
                helper.pop();
                helper.push(gone);
            }
        }
        return answer;

    }
};