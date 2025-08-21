class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int count = 0;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(j == 0){
                    dp[i][j] = mat[i][j];
                }
                else{
                    if(mat[i][j] == 0) {dp[i][j] = 0;}
                    else {dp[i][j] = dp[i][j - 1] + 1;}
                }
                int cur = dp[i][j];
                for(int k = i;k >= 0;--k){
                    cur = min(cur,dp[k][j]);
                    if(cur == 0) {break;}
                    count += cur;
                }
            }
        }
        return count;
    }
};