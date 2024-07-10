class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> answer;
        int l = 0, r = 1;
        while (r <= chars.size()){
            if (r == chars.size() || chars[l] != chars[r]){
                answer.push_back(chars[l]);
                if (r - l > 1){
                    string number = to_string(r - l);
                    generate_n(back_inserter(answer), number.size(), [i = 0, &number]() mutable { return number[i++]; });
                }
                l = r;
            }
            r++;
        }
        chars = answer;
        return chars.size();
    }
};