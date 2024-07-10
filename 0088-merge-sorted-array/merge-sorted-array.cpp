class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int firstInd = m - 1, secondInd = n - 1, insert = nums1.size() - 1;
        while (firstInd >= 0 || secondInd >= 0){
            if (firstInd < 0){
                nums1[insert--] = nums2[secondInd--];
                continue;
            }
            if (secondInd < 0){
                nums1[insert--] = nums1[firstInd--];
                continue;
            }
            if (nums1[firstInd] < nums2[secondInd]){
                nums1[insert--] = nums2[secondInd--];
            } else {
                nums1[insert--] = nums1[firstInd--];
            }
        }
        return;
    }
};