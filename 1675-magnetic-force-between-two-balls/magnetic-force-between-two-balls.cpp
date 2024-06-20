class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l = 1, r = (position.back() - position[0]) / (m - 1), median;
        while (l <= r){
            median = (l + r) / 2;
            if (check(position, m, median)){
                l = median + 1;
            } else {
                r = median - 1;
            }
        }
        return l - 1;
    }
private:
    bool check(vector<int>& position, int m, int force){
        int step;
        for (int i = 0; i < position.size(); i++){
            m--;
            step = 0;
            while(i + step < position.size() && position[i + step] - position[i] < force){
                step++;
            }
            i += step - 1;
        }
        return m <= 0; 
    }
};