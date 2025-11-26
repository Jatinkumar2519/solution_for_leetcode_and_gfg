class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k,-1)));  int mod = 1e9 + 7;
        function<int(int,int,int)> solve = [&](int x,int y,int val)->int{
            if(x >= n || y >= m) return 0;
            if(x == n - 1 && y == m - 1) return ((val + grid[n - 1][m - 1]) % k == 0) ? 1 : 0;
            if(dp[x][y][val] != -1) return dp[x][y][val];
            int total = solve(x + 1,y,(val + grid[x][y]) % k) + solve(x,y + 1,(val + grid[x][y]) % k);
            return dp[x][y][val] = total % mod;
        };
        return solve(0,0,0);
    }
};