class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total = numBottles;
        int drink = 0;
        while(total > 0){
            if(numExchange <= total){
                drink += numExchange;
                total = total - numExchange + 1;
            }
            else{
                drink += total;
                total = 0;
            }
        }
        return drink;
    }
};