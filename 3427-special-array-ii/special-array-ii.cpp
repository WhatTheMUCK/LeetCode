namespace std {
    template <typename T>
    struct hash<vector<T>> {
        inline size_t operator()(const vector<T> &v) const {
            hash<T> hasher;
            size_t hash_value = 0;
            for (const auto& element : v) {
                hash_value ^= hasher(element) + 0x9e3779b9 + (hash_value << 6) + (hash_value >> 2);
            }
            return hash_value;
        }
    };
}

class Solution {
public:

    bool check(vector<int> &query, vector<int> &wrongPositions){
        int l = query[0], r = query[1];
        auto it = upper_bound(wrongPositions.begin(), wrongPositions.end(), l);
        int wrongInd;
        if (it != wrongPositions.end()){
            wrongInd = *it;
        } else {
            wrongInd = r + 1;
        }
        cout << l <<  " " << r << " " << wrongInd << "\n";
        return  !(l < wrongInd && wrongInd <= r);
        
        
    }

    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> answer;
        vector<int> wrongPositions;
        int n = nums.size();
        for (int i = 1; i < n; i++){
            if ((nums[i] + nums[i - 1]) % 2 != 1){
                wrongPositions.push_back(i);
            }
        }
        for (vector<int> &query : queries){
            answer.push_back(check(query, wrongPositions));
        }
        return answer;
    }
};