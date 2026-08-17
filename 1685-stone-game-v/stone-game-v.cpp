class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {

        int dp[501][501];
        int n = stoneValue.size();
        vector<int> prefix(n);

        prefix[0] = stoneValue[0];
        for(int i = 1;i < n;i++){
            prefix[i] = stoneValue[i] + prefix[i - 1];
        }

        function<int(int,int)> solve = [&](int l,int r)->int{
            if(r == l) return 0;
            if(dp[l][r] != -1) return dp[l][r];
            
            int maxv = 0, curr = 0;
            int total = (l == 0) ? prefix[r] : prefix[r] - prefix[l - 1];

            for(int k = l;k < r;k++){
                curr += stoneValue[k];
                total -= stoneValue[k];

                if(curr > total){
                    maxv = max(maxv,total + solve(k + 1,r));
                }
                else if(curr < total){
                    maxv = max(maxv,curr + solve(l,k));
                }
                else{
                    maxv = max({maxv,total + solve(k + 1,r),curr + solve(l,k)});
                }
            }

            return dp[l][r] = maxv;
        };

        memset(dp,-1,sizeof(dp));
        return solve(0,n - 1);
    }
};