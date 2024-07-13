class Solution {
public:
    struct robot{
        int pos;
        int health;
        char dir;
        int posInput;

        robot(int p, int h, char d, int pIn) : pos(p), health(h), dir(d), posInput(pIn) {}
    };
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<robot> info;
        info.reserve(n);
        for (int i = 0; i < n; i++){
            info.push_back(robot(positions[i], healths[i], directions[i], i));
        }
        sort(info.begin(), info.end(), [](robot &left, robot &right){ return left.pos < right.pos; });
        deque<robot> dq;
        for (int i = 0; i < n; i++){
            robot curRobot = info[i];
            if (curRobot.dir == 'L'){
                while (!dq.empty() && dq.back().dir == 'R' && curRobot.health > 0){
                    robot leftRobot = dq.back();
                    dq.pop_back();
                    if (leftRobot.health < curRobot.health){
                        curRobot.health--;
                        leftRobot.health = 0;
                    } else if (leftRobot.health > curRobot.health){
                        curRobot.health = 0;
                        leftRobot.health--;
                    } else {
                        curRobot.health = 0;
                        leftRobot.health = 0;
                    }
                    if (leftRobot.health > 0){
                        dq.push_back(leftRobot);
                    }
                }
            }
            if (curRobot.health > 0){
                dq.push_back(curRobot);
            }
        }
        vector<pair<int, int>> helper;
        while (!dq.empty()){
            helper.push_back({dq.front().health, dq.front().posInput});
            dq.pop_front();
        }
        sort(helper.begin(), helper.end(), [](pair<int, int> &left, pair<int, int> &right){ return left.second < right.second; });
        vector<int> answer;
        for (pair<int, int> &elem : helper){
            answer.push_back(elem.first);
        }
        return answer;
    }
};