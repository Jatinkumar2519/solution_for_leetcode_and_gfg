class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dirx[4] = {-1,1,0,0};
        int diry[4] = {0,0,-1,1};
        int mod = 1e9 + 7;
        vector<vector<int>> dp(n,vector<int>(m,0));
        function<int(int,int)> solve = [&](int x,int y) -> int{
            if(dp[x][y] != 0) return dp[x][y];
            int count = 1;
            for(int d = 0;d < 4;d++){
                int nx = x + dirx[d];
                int ny = y + diry[d];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[x][y] < grid[nx][ny]){ count = (count + solve(nx,ny)) % mod; }
            }
            return dp[x][y] = count;
        };
        int count = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                count = (count + solve(i,j)) % mod;
            }
        }
        return count;
    }
};