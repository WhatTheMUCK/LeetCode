class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        array<int, 6> topsCount, bottomsCount;
        for (int i = 0; i < n; i++){
            topsCount[tops[i] - 1]++;
            bottomsCount[bottoms[i] - 1]++;
        }
        vector<pair<int, int>> topsSteps(6), bottomsSteps(6);
        for (int i = 0; i < 6; i++){
            topsSteps[i] = {i + 1, n - topsCount[i]};
            bottomsSteps[i] = {i + 1, n - bottomsCount[i]};
        }
        sort(topsSteps.begin(), topsSteps.end(), [](pair<int, int> &lhs, pair<int, int> &rhs){
            return lhs.second < rhs.second;
        });
        sort(bottomsSteps.begin(), bottomsSteps.end(), [](pair<int, int> &lhs, pair<int, int> &rhs){
            return lhs.second < rhs.second;
        });
        int answer = 1e5;
        for (const auto& [number, amount] : topsSteps){
            bool canAchieve = true;
            for (int i = 0; i < n; i++){
                if (tops[i] == number){
                    continue;
                }
                if (bottoms[i] != number){
                    canAchieve = false;
                    break;
                }
            }
            if (canAchieve){
                answer = min(answer, amount);
                break;
            }
        }
        for (const auto& [number, amount] : bottomsSteps){
            bool canAchieve = true;
            for (int i = 0; i < n; i++){
                if (bottoms[i] == number){
                    continue;
                }
                if (tops[i] != number){
                    canAchieve = false;
                    break;
                }
            }
            if (canAchieve){
                answer = min(answer, amount);
                break;
            }
        }
        return (answer == 1e5 ? -1 : answer);
    }
};