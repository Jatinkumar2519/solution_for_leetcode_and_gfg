class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        using ll = long long;
        
        int n = robot.size();
        int m = factory.size();

        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());

        vector<int> factp;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < factory[i][1];j++){
                factp.push_back(factory[i][0]);
            }
        }

        m = factp.size();
        // ll dp[101][10001];
        
        // function<ll(int,int)> solve = [&](int r,int f)->ll{
        //     if(r == n) return 0;
        //     if(f == m) return 1ll * 1e12;

        //     if(dp[r][f] != -1) return dp[r][f];
        //     return dp[r][f] = min(abs(robot[r] - factp[f]) + solve(r + 1,f + 1),solve(r,f + 1));
        // };

        // memset(dp,-1,sizeof(dp));
        // return solve(0,0);

        vector<vector<ll>> dp(n + 1,vector<ll>(m + 1,0));
        
        for(int i = 0;i < n;i++){
            dp[i][m] = 1e12;
        }
        for(int i = 0;i <= m;i++){
            dp[n][i] = 0;
        }

        for(int r = n - 1;r >= 0;r--){
            for(int f = m - 1;f >= 0;f--){
                dp[r][f] = min(abs(robot[r] - factp[f]) + dp[r + 1][f + 1],dp[r][f + 1]);
            }
        }

        return dp[0][0];
    }
};