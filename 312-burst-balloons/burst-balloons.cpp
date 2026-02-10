class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);

        int dp[301][301];
        int n = nums.size();

        function<int(int,int)> solve = [&](int i,int j)->int{
            if(i > j) return 0;

            if(dp[i][j] != -1) return dp[i][j];

            int maxv = 0;
            for(int k = i;k <= j;k++){
                maxv = max(maxv,nums[i - 1] * nums[k] * nums[j + 1] + solve(i,k - 1) + solve(k + 1,j));
            }

            return dp[i][j] = maxv;
        };

        memset(dp,-1,sizeof(dp));
        return solve(1,n - 2);
    }
};