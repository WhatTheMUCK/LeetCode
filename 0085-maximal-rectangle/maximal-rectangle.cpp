class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        
        int rows = matrix.size();
        int columns = matrix[0].size();
        vector<int> heights(columns + 1, 0);
        int maxArea = 0;
        for (vector<char> row : matrix){
            for (int i = 0; i < columns; i++){
                heights[i] = (row[i] == '1') ? heights[i] + 1 : 0;
            }

            stack<int> st;
            for (int i = 0; i < heights.size(); i++){
                while (!st.empty() && heights[i] < heights[st.top()]){
                    int h = heights[st.top()];
                    st.pop();
                    int w = st.empty() ? i : i - st.top() - 1;
                    maxArea = max(maxArea, h * w);
                }
                st.push(i);
            }
        }

        return maxArea;
    }
};