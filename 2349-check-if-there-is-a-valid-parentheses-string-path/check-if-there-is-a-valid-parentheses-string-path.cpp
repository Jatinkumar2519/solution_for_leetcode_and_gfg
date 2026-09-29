class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int dp[101][101][201];
        function<int(int,int,int)> solve = [&](int x,int y,int open)->int{
            
            if(x >= n || y >= m) return 0;

            int total = x + y + 1;
            int close = total - open;
            
            if(close > open) return 0;
            if(x == n - 1 && y == m - 1){
                return (open == close);
            }

            if(dp[x][y][open] != -1) return dp[x][y][open];

            if(x + 1 < n && solve(x + 1,y,open + (grid[x + 1][y] == '('))){
                return dp[x][y][open] = 1;
            }
            if(y + 1 < m && solve(x,y + 1,open + (grid[x][y + 1] == '('))){
                return dp[x][y][open] = 1;
            }

            return dp[x][y][open] = 0;
        };

        memset(dp,-1,sizeof(dp));
        return solve(0,0,grid[0][0] == '(');
    }
};