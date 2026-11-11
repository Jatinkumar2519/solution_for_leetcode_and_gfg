class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        int c = min(costBoth, cost1 + cost2);
        long long cost = c * 1LL * min(need1, need2);

        long long need = abs(need1 - need2);

        if(need1 > need2){
            cost += need * min(costBoth, cost1);
        }
        else{
            cost += need * min(costBoth, cost2);
        }

        return cost;
    }
};