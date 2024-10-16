class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string answer = "";
        vector<pair<int, char>> order;
        if (a > 0)
            order.push_back({a, 'a'});
        if (b > 0)
            order.push_back({b, 'b'});
        if (c > 0)
            order.push_back({c, 'c'});
        make_heap(order.begin(), order.end());
        bool threeInARow = false;
        while (!order.empty()){
            char curChar = order[0].second;
            int n = answer.size();
            threeInARow = n >= 2 && answer[n - 2] == answer[n - 1] && answer.back() == curChar;
            if (threeInARow){
                if (order.size() == 1)
                    break;
                pop_heap(order.begin(), order.end());
                curChar = order[0].second;
            }
            answer.push_back(curChar);
            pop_heap(order.begin(), order.end());
            order.back().first--;
            if (order.back().first == 0)
                order.pop_back();
            make_heap(order.begin(), order.end());
        }
        return answer;
    }
};