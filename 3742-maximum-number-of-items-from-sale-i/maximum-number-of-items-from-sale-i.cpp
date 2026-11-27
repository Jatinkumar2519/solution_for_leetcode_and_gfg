class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int maxv = 1501;

        int minPrice = INT_MAX;
        vector<int> count(maxv, 0), factorFreq(maxv, 0);
        // fact, price

        for(auto& item : items){

            factorFreq[item[0]]++;
            minPrice = min(minPrice, item[1]);
        }

        for(auto& item : items){
            int d = item[0];
            if(count[d] > 0) continue;

            for(int num = d; num < maxv; num += d){
                count[d] += factorFreq[num];
            }
        }

        int dp[1001][1501];
        function<int(int, int)> solve = [&](int idx, int price)->int{
            if(idx == n){
                int left = budget - price;
                return left / minPrice;
            }
            if(dp[idx][price] != -1) return dp[idx][price];

            int maxv = solve(idx + 1, price);
            
            if(price + items[idx][1] <= budget){
                maxv = max(maxv,
                           count[items[idx][0]] + solve(idx + 1, price + items[idx][1]));
            }

            return dp[idx][price] = maxv;
        };

        memset(dp,-1,sizeof(dp));
        return solve(0,0);
    }
};