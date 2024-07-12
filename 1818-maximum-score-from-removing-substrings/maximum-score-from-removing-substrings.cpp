class Solution {
public:
    int ab(deque<char> &helper, deque<char> &str, int x){
        int answer = 0;
        while (!helper.empty()){
            char letter = helper.front();
            helper.pop_front();
            if (letter == 'b' && !str.empty() && str.back() == 'a'){
                answer += x;
                str.pop_back();
            } else {
                str.push_back(letter);
            }
        }
        return answer;
    }

    int ba(deque<char> &helper, deque<char> &str, int y){
        int answer = 0;
        while (!helper.empty()){
            char letter = helper.front();
            helper.pop_front();
            if (letter == 'a' && !str.empty() && str.back() == 'b'){
                answer += y;
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
            answer += ab(helper, str, x);

            helper = str;
            str = deque<char>();
            answer += ba(helper, str, y);
        } else {
            answer += ba(helper, str, y);
            
            helper = str;
            str = deque<char>();
            answer += ab(helper, str, x);
        }
        return answer;
    }
};