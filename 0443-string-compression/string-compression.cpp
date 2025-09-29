class Solution {
public:
    int compress(vector<char>& chars) {
        int prevPos = 0;
        size_t l = 0, r = 0;
        for (; r <= chars.size(); ++r) {
            if (r < chars.size() && chars[r] == chars[prevPos]) {
                continue;
            }
            
            int amount = r - prevPos;
            prevPos = r;
            chars[l] = chars[r - 1];
            if (amount != 1) {
                string tmp = to_string(amount);
                for (char digit : tmp) {
                    ++l;
                    chars[l] = digit;
                }
            }
            ++l;
        }

        return l;
    }
};