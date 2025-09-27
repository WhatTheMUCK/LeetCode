class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        std::unordered_set<int> a, b;
        int n = static_cast<int>(A.size());
        int counter = 0;
        std::vector<int> answer;
        for (int i = 0; i < n; ++i) {
            a.insert(A[i]);
            b.insert(B[i]);
            counter += a.contains(B[i]);
            if (A[i] != B[i])
                counter += b.contains(A[i]);
            answer.push_back(counter);
        }

        return answer;
    }
};