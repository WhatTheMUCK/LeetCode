class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> mp;
        unordered_set<int> st;
        vector<int> C(A.size(), 0);
        for (int i = 0; i < A.size(); i++){
            mp[A[i]]++;
            mp[B[i]]++;
            if (mp[A[i]] == 2){
                st.insert(A[i]);
            }
            if (mp[B[i]] == 2){
                st.insert(B[i]);
            }
            C[i] = st.size();
        }
        return C;
    }
};