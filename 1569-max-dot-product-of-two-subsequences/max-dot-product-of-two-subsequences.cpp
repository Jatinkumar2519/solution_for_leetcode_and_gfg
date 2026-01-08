class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int dp[501][501];
        int n = nums1.size();
        int m = nums2.size();

        function<int(int,int)> solve = [&](int i,int j)->int{
            if(i == n || j == m) return INT_MIN/2;

            if(dp[i][j] != -1) return dp[i][j];
            
            int maxv = nums1[i] * nums2[j];
            maxv = max(maxv,nums1[i] * nums2[j] + solve(i + 1,j + 1));
            maxv = max(maxv,solve(i,j + 1));
            maxv = max(maxv,solve(i + 1,j));

            return dp[i][j] = maxv;
        };

        memset(dp,-1,sizeof(dp));
        return solve(0,0);
    }
};