class Solution {
public:
    int candy(vector<int>& ratings) {
        int candys = ratings.size();
        int index = 1;
        while (index < ratings.size()){
            while (index < ratings.size() && ratings[index] == ratings[index - 1]){
                index++;
            }
            int up = 0;
            while (index < ratings.size() && ratings[index] > ratings[index - 1]){
                up++;
                candys += up;
                index++;
            }

            int down = 0;
            while (index < ratings.size() && ratings[index] < ratings[index - 1]){
                down++;
                candys += down;
                index++;
            }

            candys -= min(up, down);
        }
        return candys;
    }
};