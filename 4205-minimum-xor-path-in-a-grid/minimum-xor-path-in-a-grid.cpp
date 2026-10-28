class Solution {
public:
    int minCost(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        int maxE = 0;

        for(int i = 0;i < n;i++){
            maxE = max(maxE, *max_element(grid[i].begin(), grid[i].end()));
        }
        
        int l = (maxE == 0) ? 1 : log2(maxE) + 1;
        maxE = (1 << l);

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(maxE, -1)));

        function<int(int,int,int)> solve = [&](int i, int j, int x)->int{

            if(i == n - 1 && j == m - 1) return x ^ grid[i][j];
            if(dp[i][j][x] != -1) return dp[i][j][x];

            int res = INT_MAX;
            if(i + 1 < n) res = min(res, solve(i + 1, j, x ^ grid[i][j]));
            if(j + 1 < m) res = min(res, solve(i, j + 1, x ^ grid[i][j]));

            return dp[i][j][x] = res;
        };
        
        return solve(0,0,0);
    }
};