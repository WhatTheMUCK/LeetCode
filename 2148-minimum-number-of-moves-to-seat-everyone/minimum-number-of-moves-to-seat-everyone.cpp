class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        return accumulate(seats.begin(), seats.end(), 0, [i = 0, &students, &seats](int acc, int x) mutable {
            return acc + abs(students[i++] - x); 
        });
    }
};