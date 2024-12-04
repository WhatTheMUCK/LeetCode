class Solution {
public:
    int alphabetSize = 'z' - 'a' + 1;

    char cyclicChar(char letter){
        return 'a' + (letter - 'a' + 1) % alphabetSize;
    }

    bool temp(string& str1, string& str2, int str1Ind, int str2Ind){
        int n1 = str1.size(), n2 = str2.size();
        if (str2Ind == n2){
            return true;
        }
        if (str1Ind == n1){
            return false;
        }

        bool option1, option2;
        if (str1[str1Ind] == str2[str2Ind] || cyclicChar(str1[str1Ind]) == str2[str2Ind]){
            return temp(str1, str2, str1Ind + 1, str2Ind + 1);
        } else {
            return temp(str1, str2, str1Ind + 1, str2Ind);
        }
    }

    bool canMakeSubsequence(string str1, string str2) {
        return temp(str1, str2, 0, 0);
    }
};