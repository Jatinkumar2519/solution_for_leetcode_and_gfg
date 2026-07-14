class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int mod = 1e9 + 7;
        int n = nums.size();

        int dp[201][201][201];
        function<int(int,int,int)> solve = [&](int i,int g1,int g2)->int{
            if(i == n) return (g1 == g2 && g1 > 0);
            
            if(dp[i][g1][g2] != -1) return dp[i][g1][g2];
            int count = solve(i + 1,g1,g2);
            count = (count + solve(i + 1,g1,__gcd(g2,nums[i]))) % mod;
            count = (count + solve(i + 1,__gcd(g1,nums[i]),g2)) % mod;

            return dp[i][g1][g2] = count;
        };

        memset(dp,-1,sizeof(dp));
        return solve(0,0,0);
    }
};