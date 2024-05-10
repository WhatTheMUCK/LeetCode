class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        vector<int> humans(3 * 10e4 + 1, 0);
        int minimum = 1e5, maximum = -1;
        for (int human : people){
            humans[human]++;
            minimum = min(minimum, human);
            maximum = max(maximum, human);
        }
        // for (int i = minimum; i <= maximum; i++){
        //     cout << humans[i] << " ";
        // }
        //cout << "\n";
        int l = minimum, r = maximum, boats = 0;
        //cout << l << " " << r << "\n";
        while (l <= r){
            // cout << "1)l: " << l << " r: " << r << " humans[l]: " << humans[l] << " humans[r]: " << humans[r] << " boats: " << boats << "\n";
            while (l <= r && humans[l] <= 0){
                l++;
            }
            while (r >= l && humans[r] <= 0){
                r--;
            }
            if (l > r){
                break;
            }
            //cout << "2)l: " << l << " r: " << r << " humans[l]: " << humans[l] << " humans[r]: " << humans[r] << " boats: " << boats << "\n";
            if (l == r){
                if (l + r <= limit){
                    boats += (humans[l] + 1) / 2;
                } else {
                    boats += humans[l];
                }
                humans[l] = 0;
            } else {
                minimum = min(humans[l], humans[r]);
                if (l + r <= limit){
                    humans[l] -= minimum;
                }
                humans[r] -= minimum;
                boats += minimum;
            }
        } 
        return boats;
    }
};