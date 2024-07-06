class Solution {
public:
    int passThePillow(int n, int time) {
        n--;
        int rotating = time / n;
        if (rotating % 2 == 1)
            return (n + 1) - time % n;
        return 1 + time % n;
    }
};