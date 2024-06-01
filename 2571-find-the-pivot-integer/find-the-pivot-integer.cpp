class Solution {
public:
    int pivotInteger(int n) {
        for (int i = 1; i <= n; i++){
            if ((n * (n + 1) / 2) - ((i - 1) * (i - 1  + 1) / 2) == i * (i + 1) / 2){
                return i;
            }
        }
        return -1;
    }
};