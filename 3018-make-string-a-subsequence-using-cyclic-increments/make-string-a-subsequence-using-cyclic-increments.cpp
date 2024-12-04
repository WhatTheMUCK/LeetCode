class Solution {
public:
    int alphabetSize = 'z' - 'a' + 1;

    char cyclicChar(char letter){
        return 'a' + (letter - 'a' + 1) % alphabetSize;
    }

    bool canMakeSubsequence(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size();
        int str1Ind = 0, str2Ind = 0;
        while (str1Ind < n1 && str2Ind < n2){
            if (str1[str1Ind] == str2[str2Ind] || cyclicChar(str1[str1Ind]) == str2[str2Ind]){
                str1Ind++, str2Ind++;
            } else {
                str1Ind++;
            }
        }
        return str2Ind == n2;
    }
};