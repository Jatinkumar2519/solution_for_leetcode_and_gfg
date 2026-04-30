class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        // static int dp[201][201][1001];

        // function<int(int,int,int)> solve = [&](int i,int j,int k)->int{
        //     if(k < 0) return INT_MIN;
        //     if(i == n - 1 && j == m - 1) return 0;

        //     if(dp[i][j][k] != -1) return dp[i][j][k];
            
        //     int maxv = INT_MIN;
        //     if(i + 1 < n){
        //         int res = solve(i + 1,j,k - (grid[i + 1][j] != 0));
        //         if(res != INT_MIN)
        //             maxv = max(maxv,grid[i + 1][j] + res);
        //     }

        //     if(j + 1 < m){
        //         int res = solve(i,j + 1,k - (grid[i][j + 1] != 0));
        //         if(res != INT_MIN)
        //             maxv = max(maxv,grid[i][j + 1] + res);
        //     }

        //     return dp[i][j][k] = maxv;
        // };

        // memset(dp,-1,sizeof(dp));

        // int res = solve(0,0,K - (grid[0][0] != 0));
        // return (res == INT_MIN ? -1 : grid[0][0] + res);

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k + 1)));

        for(int i = n - 1;i >= 0;i--){
            for(int j = m - 1;j >= 0;j--){
                for(int l = 0;l <= k;l++){
                    if(i == n - 1 && j == m - 1){
                        dp[i][j][l] = 0;
                    }
                    else{
                        int maxv = INT_MIN;
                        
                        if(i + 1 < n){
                            int newl = l - (grid[i + 1][j] != 0);
                            if(newl >= 0 && dp[i + 1][j][newl] != INT_MIN){
                            maxv = max(maxv,grid[i + 1][j] + dp[i + 1][j][newl]);
                            }
                        }

                        if(j + 1 < m){
                            int newl = l - (grid[i][j + 1] != 0);
                            if(newl >= 0 && dp[i][j + 1][newl] != INT_MIN){
                            maxv = max(maxv,grid[i][j + 1] + dp[i][j + 1][newl]);
                            }
                        }

                        dp[i][j][l] = maxv;
                    }
                }
            }
        }

        return (dp[0][0][k] == INT_MIN ? -1 : dp[0][0][k]);
    }
};