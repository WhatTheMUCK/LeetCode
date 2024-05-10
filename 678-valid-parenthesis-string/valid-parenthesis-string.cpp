class Solution {
public:
    bool checkValidString(string s) {
        int leftMin = 0, leftMax = 0;
        for (char elem : s){
            if (elem == '('){
                leftMin++;
                leftMax++;
            }
            if (elem == ')'){
                leftMin--;
                leftMax--;
            }
            if (elem == '*'){
                leftMin--;
                leftMax++;
            }
            if (leftMax < 0){
                return false;
            }
            if (leftMin < 0){
                leftMin = 0;
            }
        }
        return leftMin == 0;
    }
};