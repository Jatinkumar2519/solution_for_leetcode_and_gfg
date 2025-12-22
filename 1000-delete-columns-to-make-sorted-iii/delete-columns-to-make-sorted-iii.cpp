class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int maxv = 1;
        int n = strs.size();
        int m = strs[0].size();
        vector<int> dp(m,1);
        for(int i = 0;i < m;i++){
            for(int j = 0;j < i;j++){
                bool flag = true;
                for(int k = 0;k < n;k++){
                    if(strs[k][j] > strs[k][i]){
                        flag = false;
                        break;
                    }
                }
                if(flag && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                }
            }
            maxv = max(maxv,dp[i]);
        }
        return m - maxv;
    }
};