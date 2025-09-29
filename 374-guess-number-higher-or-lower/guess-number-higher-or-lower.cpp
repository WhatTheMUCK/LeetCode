/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long l = 1, r = n + 1ll;
        while (l < r) {
            long long m = (l + r) / 2;
            int answer = guess(m);
            if (answer == 0) {
                return m;
            }

            if (answer == -1) { // m > pick
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return l;
    }
};