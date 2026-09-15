class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        vector<vector<bool>> isPalin(n,vector<bool>(n));

        for(int i = 0;i < n;i++){
            isPalin[i][i] = true;
            if(i + 1 < n && s[i] == s[i + 1]){
                isPalin[i][i + 1] = true;
            }
        }

        for(int len = 3;len <= n;len++){
            for(int i = 0;i <= n - len;i++){
                int j = i + len - 1;

                isPalin[i][j] = (isPalin[i + 1][j - 1] && (s[i] == s[j]));
            }
        }

        int dp[2001];
        function<int(int)> solve = [&](int idx)->int{
            if(idx == n) return 0;
            if(dp[idx] != -1) return dp[idx];

            int maxv = solve(idx + 1);
            for(int i = idx + k - 1;i < n;i++){
                if(isPalin[idx][i]){
                    maxv = max(maxv,1 + solve(i + 1));
                }
            }

            return dp[idx] = maxv;
        };

        memset(dp,-1,sizeof(dp));
        return solve(0);
    }
};