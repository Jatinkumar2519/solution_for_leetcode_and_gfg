class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int mod = 1e9 + 7;
        vector<int> dp(n + 1,0);
        dp[1] = 1;
        for(int i = 1;i <= n;i++){
            for(int j = i + delay;j < min(n + 1,i + forget);j++){
                dp[j] = (dp[j] + dp[i]) % mod;
            }
        }
        int sum = 0;
        for(int i = 1;i <= n;i++){
            if(i + forget > n){
                sum = (sum + dp[i]) % mod;
            }
        }
        return sum;
    }
};