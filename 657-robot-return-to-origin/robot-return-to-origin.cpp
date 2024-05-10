class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (char elem : moves){
            if (elem == 'U')
                y++;
            else if (elem == 'D')
                y--;
            else if (elem == 'R')
                x++;
            else if (elem == 'L')
                x--;
        }
        return (x == 0 && y == 0);
    }
};