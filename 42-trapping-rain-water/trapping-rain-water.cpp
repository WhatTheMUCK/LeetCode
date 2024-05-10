class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, lmax = -1, rmax = -1, answer = 0;
        while (l < r){
            lmax = max(height[l], lmax);
            rmax = max(height[r], rmax);
            answer += lmax < rmax ? lmax - height[l++] : rmax - height[r--];
        }
        return answer;
    }
};