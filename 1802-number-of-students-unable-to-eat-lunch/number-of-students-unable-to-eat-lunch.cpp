class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        unordered_map<int, int> typeStudent;
        for (int i = 0; i < 2; i++){
            typeStudent[i] = 0;
        }

        for (int i = 0; i < sandwiches.size(); i++){
            typeStudent[students[i]]++;
        }

        int i = 0;
        for (i; i < sandwiches.size(); i++){
            if (typeStudent[sandwiches[i]] > 0){
                typeStudent[sandwiches[i]]--;
            } else {
                break;
            }
        }
        return sandwiches.size() - i;

    }
};