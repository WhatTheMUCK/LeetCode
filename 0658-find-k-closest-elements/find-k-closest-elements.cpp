class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = static_cast<int>(arr.size());
        if (k >= n) {
            return arr;
        }

        std::deque<int> answer;
        std::vector<int>::iterator it = std::lower_bound(arr.begin(), arr.end(), x);
        if (it == arr.end()) {
            return std::vector<int>(arr.begin() + (n - k), arr.end());
        }

        int r = it - arr.begin(), l = r - 1;
        while (l >= 0 && r < n && answer.size() < k) {
            int diffL = std::abs(x - arr[l]), diffR = std::abs(x - arr[r]);
            if (diffL <= diffR) {
                answer.push_front(arr[l]);
                --l;
                continue;
            }

            answer.push_back(arr[r]);
            ++r;
        }

        while (l >= 0 && answer.size() < k) {
            answer.push_front(arr[l]);
            --l;
        }

        while (r < n && answer.size() < k) {
            answer.push_back(arr[r]);
            ++r;
        }

        return std::vector<int>(answer.begin(), answer.end());
    }
};