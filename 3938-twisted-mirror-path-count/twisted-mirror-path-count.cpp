class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int mod = 1e9 + 7;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(3, -1)));
        function<int(int, int, int)> solve = [&](int i, int j, int dir) -> int {
            if (i >= n || j >= m)
                return 0;
            if (i == n - 1 && j == m - 1)
                return 1;
            if (dp[i][j][dir + 1] != -1)
                return dp[i][j][dir + 1];
            if (grid[i][j] == 1) {
                if (dir == 0)
                    return dp[i][j][dir + 1] = solve(i, j + 1, 1);
                if (dir == 1)
                    return dp[i][j][dir + 1] = solve(i + 1, j, 0);
            }
            return dp[i][j][dir + 1] =
                       (solve(i + 1, j, 0) + solve(i, j + 1, 1)) % mod;
        };
        return solve(0, 0, -1);
    }
};