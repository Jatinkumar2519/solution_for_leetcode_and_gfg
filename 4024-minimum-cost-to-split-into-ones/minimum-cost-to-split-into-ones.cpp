class Solution {
public:
    int minCost(int n) {
        static int dp[501];
        memset(dp,-1,sizeof(dp));

        function<int(int)> solve = [&](int num)->int{
            if(num == 1) return 0;
            if(dp[num] != -1) return dp[num];

            int minv = INT_MAX;
            for(int i = 1;i < num;i++){
                minv = min(minv,i * (num - i) + solve(i) + solve(num - i));
            }

            return dp[num] = minv;
        };

        return solve(n);
    }
};