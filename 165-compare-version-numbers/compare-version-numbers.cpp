class Solution {
public:
    int compareVersion(string version1, string version2) {
        int iter1 = -1, iter2 = -1;
        string temp1, temp2;
        while (iter1 < (int)version1.size() || iter2 < (int)version2.size()){
            temp1 = "";
            temp2 = "";
            iter1 = min(iter1 + 1, (int)version1.size());
            iter2 = min(iter2 + 1, (int)version2.size());;
            //cout << iter1 << " " << iter2 << "\n";
            bool leadingZero = true;
            while (version1[iter1] != '.' && iter1 < version1.size()){
                if (version1[iter1] != '0'){
                    leadingZero = false;
                    temp1 += version1[iter1];
                } else if (version1[iter1] == '0' && !leadingZero){
                    temp1 += version1[iter1];
                }
                iter1++;
            }

            leadingZero = true;
            while (version2[iter2] != '.' && iter2 < version2.size()){
                if (version2[iter2] != '0'){
                    leadingZero = false;
                    temp2 += version2[iter2];
                } else if (version2[iter2] == '0' && !leadingZero){
                    temp2 += version2[iter2];
                }
                iter2++;
            }
            //cout << "temp1: " << temp1 << " temp2: " << temp2 << "\n";
            if (temp1.size() < temp2.size()){
                return -1;
            } else if (temp1.size() > temp2.size()){
                return 1;
            } else {
                for (int i = 0; i < temp1.size(); i++){
                    if (temp1[i] < temp2[i]){
                        return -1;
                    } else if (temp1[i] > temp2[i]){
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
};