class Solution {
public:
    int maximumSwap(int num) {
        if (num < 10)
            return num;
        int n = (int)log10(num) + 1;
        vector<int> digits(n);
        for (int i = 0; i < n; i++, num /= 10){
            int curDigit = num % 10;
            int curInd = n - (i + 1);
            digits[curInd] = curDigit;
        }
        int l = 1;
        while (l < n && digits[l] <= digits[l - 1])
            l++;
        if (l != n){
            int maxDigitInd = l;
            for (int i = l; i < n; i++)
                if (digits[i] >= digits[maxDigitInd])
                    maxDigitInd = i;
            int swapInd = upper_bound(digits.begin(), digits.begin() + (l - 1), digits[maxDigitInd], greater<int>()) - digits.begin();
            swap(digits[swapInd], digits[maxDigitInd]);
        }
        int answer = 0;
        for (int i = 0; i < n; i++)
            answer = answer * 10 + digits[i];
        return answer;
    }
};