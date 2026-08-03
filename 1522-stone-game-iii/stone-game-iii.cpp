class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        // int dp[50001];

        // function<int(int)> solve = [&](int idx)->int{
        //     if(idx == n) return 0;
        //     if(dp[idx] != -1) return dp[idx];

        //     int maxV = INT_MIN;
        //     int sum = 0;

        //     for(int i = 0;i < 3 && idx + i < n;i++){
        //         sum += stoneValue[idx + i];
        //         maxV = max(maxV,sum - solve(idx + i + 1));
        //     }

        //     return dp[idx] = maxV;
        // };

        // memset(dp,-1,sizeof(dp));
        // int val = solve(0);

        vector<int> dp(n + 1,0);
        
        for(int i = n - 1;i >= 0;i--){

            int sum = 0;
            int maxv = INT_MIN;
            for(int j = 0;j < 3 && j + i < n;j++){
                sum += stoneValue[i + j];
                maxv = max(maxv,sum - dp[i + j + 1]);
            }

            dp[i] = maxv;
        }

        int val = dp[0];

        if(val == 0) return "Tie";
        return (val > 0) ? "Alice" : "Bob";
    }
};