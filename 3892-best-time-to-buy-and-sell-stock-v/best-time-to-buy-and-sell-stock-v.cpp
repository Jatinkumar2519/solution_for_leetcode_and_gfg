class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        using ll = long long;
        const ll NEG_INF = -1e18;
        int n = prices.size();

        static ll dp[1001][501][3];
        memset(dp, -1, sizeof(dp));

        function<ll(int,int,int)> solve = [&](int idx, int done, int state) -> ll {
            if (idx == n || done == k)
                return (state == 0) ? 0 : NEG_INF;

            ll &res = dp[idx][done][state];
            if (res != -1) return res;

            res = solve(idx + 1, done, state);

            if (state == 0) {
                res = max(res, -prices[idx] + solve(idx + 1, done, 1));
                res = max(res,  prices[idx] + solve(idx + 1, done, 2));
            }
            else if (state == 1) {
                res = max(res, prices[idx] + solve(idx + 1, done + 1, 0));
            }
            else {
                res = max(res, -prices[idx] + solve(idx + 1, done + 1, 0));
            }
            return res;
        };

        return solve(0, 0, 0);
    }
};
