class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dirx = {-1,-1,1,1};
        vector<int> diry = {-1,1,1,-1};
        int dp[501][501][4][2];
        memset(dp,-1,sizeof(dp));
        function<int(int,int,int,bool,int)> solve = [&](int x,int y,int d,bool turn,int target) -> int {
            if(x < 0 || y < 0 || x >= n || y >= m || target != grid[x][y]) return 0;
            if(dp[x][y][d][turn] != -1) return dp[x][y][d][turn];
            int maxval = 0;
            if(turn){
                maxval = solve(x + dirx[d],y + diry[d],d,turn,2 - target);
            }
            else{
                int r = (d == 3) ? 0 : d + 1;
                maxval = max({solve(x + dirx[d],y + diry[d],d,turn,2 - target),solve(x + dirx[r],y + diry[r],r,true,2 - target)});
            }
            return dp[x][y][d][turn] = maxval + 1;
        };
        int maxval = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j] == 1){
                    for(int d = 0;d < 4;d++){
                        maxval = max(maxval,1 + solve(i + dirx[d],j + diry[d],d,false,2));
                    }
                }
            }
        }
        return maxval;
    }
};