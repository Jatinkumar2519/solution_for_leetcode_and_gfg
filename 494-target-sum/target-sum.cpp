class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int target) {
        target += 1000;
        int n = arr.size();

        static int dp[21][2001];
        function<int(int,int)> solve = [&](int idx,int sum)->int{
            if(n == idx) return sum == target;
            
            if(dp[idx][sum] != -1) return dp[idx][sum];
            
            return dp[idx][sum] = solve(idx + 1,sum + arr[idx]) + solve(idx + 1,sum - arr[idx]);
        };
            
        memset(dp,-1,sizeof(dp));
        return solve(0,1000);
    }
};