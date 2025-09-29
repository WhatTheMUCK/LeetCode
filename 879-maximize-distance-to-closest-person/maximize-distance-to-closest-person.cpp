class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = static_cast<int>(seats.size());
        vector<int> closestLeft(n + 1, -1e6), closestRight(n + 1, 1e6);
        for (int i = 0; i < n; ++i) {
            if (seats[i] == 1) {
                closestLeft[i + 1] = i;
            } else {
                closestLeft[i + 1] = closestLeft[i];
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            if (seats[i] == 1) {
                closestRight[i] = i;
            } else {
                closestRight[i] = closestRight[i + 1];
            }
        }

        int maxDistance = 0;

        for (int i = 0; i < n; ++i) {
            int tempDistance = min(i - closestLeft[i + 1], closestRight[i] - i);
            maxDistance = max(maxDistance, tempDistance);
        }

        return maxDistance;
    }
};