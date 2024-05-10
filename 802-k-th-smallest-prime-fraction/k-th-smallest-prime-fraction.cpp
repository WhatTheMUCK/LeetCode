class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        double l = 0, r = 1, m;
        double maxFrac;
        vector<int> res;
        while (l <= r){
            m = (l + r) / 2;
            int j = 1, total = 0, num = 0, den = 0;
            maxFrac = 0;
            for (int i = 0; i < arr.size(); ++i){
                while(j < arr.size() && arr[i] >= arr[j] * m) ++j;
                total += (int)arr.size() - j;
                if (j < arr.size() && maxFrac < arr[i] * 1.0 / arr[j]){
                    maxFrac = arr[i] * 1.0 / arr[j];
                    num = i; den = j;
                }
            }

            if (total == k){
                res = {arr[num], arr[den]};
                break;
            }
            if (total > k){
                r = m;
            } else {
                l = m;
            }
        }
        return res;
    }
};