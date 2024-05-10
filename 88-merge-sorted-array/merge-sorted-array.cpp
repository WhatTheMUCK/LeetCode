class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l1 = m - 1, l2 = n - 1, k = n + m - 1;
        while (l1 >= 0 || l2 >= 0){
            if (l1 < 0){
                nums1[k] = nums2[l2]; 
                l2--;
                k--;
            } else if (l2 < 0){
                nums1[k] = nums1[l1]; 
                l1--;
                k--;
            } else {
                if (nums1[l1] > nums2[l2]){
                    nums1[k] = nums1[l1];
                    l1--;
                    k--;
                } else {
                    nums1[k] = nums2[l2];
                    l2--;
                    k--;
                }
            }
        }
    }
};