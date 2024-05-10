class Solution {
public:
    bool CorrectIP(vector<string> ip){
        int helper;
        for (string elem : ip){
            if (elem[0] == '0' && elem.size() > 1 || elem.size() > 3)
                return false;
            helper = stoi(elem);
            cout << helper << "\n";
            if (helper > 255)
                return false;
        }
        return true;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ip(4);
        vector<string> answer;
        for (int first = 1; first < (int)s.size() - 2; first++){
            for (int second = first + 1; second < (int)s.size() - 1; second++){
                for (int third = second + 1; third < (int)s.size(); third++){
                    ip[0] = s.substr(0, first);
                    ip[1] = s.substr(first, second - first);
                    ip[2] = s.substr(second, third - second);
                    ip[3] = s.substr(third);
                    if (CorrectIP(ip)){
                        answer.push_back(ip[0] + "." + ip[1] + "." + ip[2] + "." + ip[3]);
                    }
                }
            }
        }
        return answer;
    }
};