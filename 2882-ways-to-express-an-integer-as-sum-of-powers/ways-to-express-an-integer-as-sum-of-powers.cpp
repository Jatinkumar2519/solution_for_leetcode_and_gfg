class Solution {
public:
    int numberOfWays(int num, int x) {
        vector<int> arr;
        int mod = 1e9 + 7;
        for(int i = 1;pow(i,x) <= num;i++){
            arr.push_back(pow(i,x));
        }
        int n = arr.size();
        vector<vector<int>> dp(n + 1,vector<int>(num + 1,0));
        dp[0][0] = 1;
        for(int i = 1;i <= n;i++){
            for(int j = 0;j <= num;j++){
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
                if(j - arr[i - 1] >= 0){
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - arr[i - 1]]) % mod;
                }
            }
        }
        return dp[n][num];
    }
};