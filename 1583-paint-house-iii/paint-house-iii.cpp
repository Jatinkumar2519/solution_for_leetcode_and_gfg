class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int n, int k,
                int m) {
        int dp[101][101][21];

        function<int(int, int, int)> solve = [&](int curr, int nbr, int last) {
            if (curr == n)
                return (nbr == m) ? 0 : INT_MAX;
            if (nbr > m)
                return INT_MAX;

            if (dp[curr][nbr][last] != -1)
                return dp[curr][nbr][last];

            int minv = INT_MAX;

            if (houses[curr] != 0) {
                minv =
                    solve(curr + 1, nbr + (houses[curr] != last), houses[curr]);
            } else {
                for (int i = 0; i < k; i++) {
                    int res = solve(curr + 1, nbr + (last != (i + 1)), i + 1);
                    if (res != INT_MAX) {
                        minv = min(minv, res + cost[curr][i]);
                    }
                }
            }
            return dp[curr][nbr][last] = minv;
        };

        memset(dp, -1, sizeof(dp));
        int ans = solve(0, 0, 0);

        return (ans == INT_MAX) ? -1 : ans;
    }
};