class Solution {
public:
    int counter(deque<char> &helper, deque<char> &str, char first, char second, int x){
        int answer = 0;
        while (!helper.empty()){
            char letter = helper.front();
            helper.pop_front();
            if (letter == second && !str.empty() && str.back() == first){
                answer += x;
                str.pop_back();
            } else {
                str.push_back(letter);
            }
        }
        return answer;
    }

    int maximumGain(string s, int x, int y) {
        vector<int> visited(s.size(), 0);
        deque<char> helper(s.begin(), s.end()), str;
        int answer = 0;
        if (x >= y){
            answer += counter(helper, str, 'a', 'b', x);

            helper = str;
            str = deque<char>();
            answer += counter(helper, str, 'b', 'a', y);
        } else {
            answer += counter(helper, str, 'b', 'a', y);

            helper = str;
            str = deque<char>();
            answer += counter(helper, str, 'a', 'b', x);
        }
        return answer;
    }
};