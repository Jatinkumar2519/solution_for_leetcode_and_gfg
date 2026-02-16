class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int n = cost.size();
        const int inf = 1e5;
        int m = cost[0].size();

        vector<int> mincost(m,inf);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                mincost[j] = min(mincost[j],cost[i][j]);
            }
        }

        int dp[12][1 << 12];

        function<int(int, int)> solve = [&](int i, int mask) -> int {
            if (i == n) {
                int rest = 0;
                for(int j = 0;j < m;j++){
                    if(mask & (1 << j)) continue;
                    rest += mincost[j];
                }
                
                return rest;
            }

            if (dp[i][mask] != -1)
                return dp[i][mask];

            int minv = inf;
            for (int j = 0; j < m; j++) {
                minv = min(minv, cost[i][j] + solve(i + 1, mask | (1 << j)));
            }

            return dp[i][mask] = minv;
        };

        memset(dp, -1, sizeof(dp));
        return solve(0, 0);
    }
};