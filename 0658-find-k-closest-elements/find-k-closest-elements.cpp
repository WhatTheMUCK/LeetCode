class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() - 1, m;
        while (l <= r){
            m = l + (r - l) / 2;
            //cout << "l: " << l << " r: " << r << " m: " << m << " x: " << x << " arr[m]: " << arr[m] << "\n";
            if (x >= arr[m]){
                l = m + 1;
            } else{
                r = m - 1;
            } 
        }
        cout << l << " " << r << "\n";
        deque<int> closest;
        int start = l;
        l = start - 1, r = start;
        while (k > 0){
            if (l < 0){
                closest.push_back(arr[r]);
                r++;
            } else if (r >= arr.size()){
                closest.push_front(arr[l]);
                l--;
            } else {
                if (abs(arr[l] - x) <= abs(arr[r] - x)){
                    closest.push_front(arr[l]);
                    l--;
                } else {
                    closest.push_back(arr[r]);
                    r++;
                }
            }
            k--;
        }

        vector<int> answer;
        while (!closest.empty()){
            answer.push_back(closest.front());
            closest.pop_front();
        }

        return answer;
    }
};