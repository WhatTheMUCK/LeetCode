class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> closestLeft(seats.size(), -1e6), closestRight(seats.size(), 1e6);
        for (int i = 1; i < seats.size(); i++){
            if (seats[i - 1] == 1){
                closestLeft[i] = i - 1;
            } else {
                closestLeft[i] = closestLeft[i - 1]; 
            }
        }

        // for (int i = 0; i < closestLeft.size(); i++){
        //     cout << closestLeft[i] << " ";
        // }
        // cout << "\n";

        for (int i = seats.size() - 2; i >= 0; i--){
            if (seats[i + 1] == 1){
                closestRight[i] = i + 1;
            } else {
                closestRight[i] = closestRight[i + 1];
            }
        }

        // for (int i = 0; i < closestRight.size(); i++){
        //     cout << closestRight[i] << " ";
        // }
        // cout << "\n";

        int maxDistance = 0, distance;
        for (int i = 0; i < seats.size(); i++){
            distance = min(closestRight[i] - i, i - closestLeft[i]);
            if (distance > maxDistance && seats[i] == 0){
                maxDistance = distance;
            }
        }
        return maxDistance;
    }
};