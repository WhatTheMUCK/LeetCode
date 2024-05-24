class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, heightL = 0, heightR = 0, water = 0;
        while (l < r){
            heightL = max(heightL, height[l]);
            heightR = max(heightR, height[r]);
            water += heightL < heightR ? heightL - height[l++] : heightR - height[r--];
        }
        return water;
    }
};