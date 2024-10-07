class Solution {
public:
    int minLength(string s) {
        int length = s.size();
        int l = 0, r = 1;
        vector<bool> visited(length, false);
        while (r < s.size()){
            if (l >= 0 && visited[l] == false && (s[l] == 'A' && s[r] == 'B' || s[l] == 'C' && s[r] == 'D')){
                length -= 2;
                visited[l] = true;
                visited[r] = true;
                while (l >= 0 && visited[l] == true)
                    l--;
                r++;
            } else {
                l = r;
                r++;
            }
        }
        return length;
    }
};