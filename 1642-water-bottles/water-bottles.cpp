class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int answer = numBottles;
        int empty = numBottles;
        while (empty >= numExchange){
            answer += empty / numExchange;
            empty = empty / numExchange + empty % numExchange;
        }
        return answer;
    }
};