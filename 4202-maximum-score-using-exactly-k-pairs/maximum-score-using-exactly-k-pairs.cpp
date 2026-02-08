class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int p) {
        using ll = long long;
        int n = nums1.size();
        int m = nums2.size();

        // ll dp[101][101][101];
        ll inf = -1e15;

        // function<ll(int,int,int)> solve = [&](int i,int j,int k)->ll{
        //     if(k < 0) return inf;

        //     if(i == n || j == m){
        //         if(k != 0) return inf;
        //         return 0;
        //     }

        //     if(dp[i][j][k] != -1) return dp[i][j][k];

        //     return dp[i][j][k] = max({solve(i + 1,j + 1,k),solve(i +
        //     1,j,k),solve(i,j + 1,k),(nums1[i] * 1LL * nums2[j]) + solve(i +
        //     1,j + 1,k - 1)});
        // };

        // memset(dp,-1,sizeof(dp));
        // return solve(0,0,K);

        vector<vector<vector<ll>>> dp(
            n + 1, vector<vector<ll>>(m + 1, vector<ll>(p + 1)));
        for (int i = 0; i <= n; i++)
            for (int k = 0; k < p; k++)
                dp[i][m][k] = inf;

        for (int j = 0; j <= m; j++)
            for (int k = 0; k < p; k++)
                dp[n][j][k] = inf;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                for (int k = p - 1; k >= 0; k--) {
                    dp[i][j][k] = max({dp[i + 1][j + 1][k], dp[i + 1][j][k],
                                       dp[i][j + 1][k],
                                       (nums1[i] * 1LL * nums2[j]) +
                                           dp[i + 1][j + 1][k + 1]});
                }
            }
        }

        return dp[0][0][0];
    }
};