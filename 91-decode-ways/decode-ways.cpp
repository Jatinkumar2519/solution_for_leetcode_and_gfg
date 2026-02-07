class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();

        int dp[101];
        function<int(int)> solve = [&](int i)->int{
            if(i == n) return 1;

            if(dp[i] != -1) return dp[i];

            if(s[i] == '0') return dp[i] = INT_MAX;

            int count = solve(i + 1);

            if(count == INT_MAX) count = 0;

            if(i + 2 <= n && stoi(s.substr(i,2)) <= 26){
                int res = solve(i + 2);

                if(res != INT_MAX){
                    count += res;
                }
            }

            return dp[i] = count;
        };

        memset(dp,-1,sizeof(dp));
        int res = solve(0);

        return (res != INT_MAX) ? res : 0;
    }
};