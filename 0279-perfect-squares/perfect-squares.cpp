#include <vector>

vector<int> dp(1e4 + 1, -1);
vector<int> squares;

class Solution {
public:
    int calculate(int n) {
        if (dp[n] != -1) {
            return dp[n];
        }

        if (n == 0) {
            dp[n] = 0;
            return dp[n]; 
        }

        int temp = n;
        int nSize = static_cast<int>(squares.size());
        for (int i = 0; i < nSize && squares[i] <= n; ++i) {
            temp = min(temp, calculate(n - squares[i]));
        }
        dp[n] = temp + 1;
        return dp[n];
    }

    int numSquares(int n) {
        for (int i = 1; i * i <= n; ++i) {
            squares.push_back(i * i);
        }
        return calculate(n);
    }
};