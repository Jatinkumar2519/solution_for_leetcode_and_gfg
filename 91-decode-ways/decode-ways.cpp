class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();

        // int dp[101];
        // function<int(int)> solve = [&](int i)->int{
        //     if(i == n) return 1;

        //     if(dp[i] != -1) return dp[i];

        //     if(s[i] == '0') return 0;

        //     int count = solve(i + 1);

        //     if(i + 2 <= n && stoi(s.substr(i,2)) <= 26){
        //         count += solve(i + 2);
        //     }

        //     return dp[i] = count;
        // };

        // memset(dp,-1,sizeof(dp));
        
        // return  solve(0);

        vector<int> dp(n + 1);
        dp[n] = 1;

        for(int i = n - 1;i >= 0;i--){
            if(s[i] == '0'){
                dp[i] = 0;
                continue;
            }
            
            dp[i] += dp[i + 1];
            if(i + 2 <= n && stoi(s.substr(i,2)) <= 26){
                dp[i] += dp[i + 2];
            }
        }

        return dp[0];
    }
};