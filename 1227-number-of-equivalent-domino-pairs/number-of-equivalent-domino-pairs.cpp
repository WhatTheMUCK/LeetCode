namespace std {
    template<>
    struct hash<std::vector<int>> {
        size_t operator()(const std::vector<int>& v) const {
            size_t seed = 0;
            for (auto i : v) {
                seed ^= hash<int>()(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    };
}

class Solution {
 public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int answer = 0;
        for (vector<int> &elem : dominoes){
            if (domino.contains(elem)){
                domino[elem]++;
            } else if (domino.contains({elem[1], elem[0]})){
                domino[{elem[1], elem[0]}]++;
            } else {
                domino[elem]++;
            }
        }
        for (const auto &[_, amount] : domino){
            answer += (amount * (amount - 1)) / 2;
        }
        return answer;
    }
 
 private:
    std::unordered_map<std::vector<int>, int> domino;
};