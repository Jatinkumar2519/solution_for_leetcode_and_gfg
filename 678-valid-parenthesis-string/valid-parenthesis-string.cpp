class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        int dp[101][101][101];

        function<bool(int, int, int)> solve = [&](int idx, int open,
                                                  int close) -> bool {
            if (idx == n)
                return open == close;
            if (open < close)
                return false;

            if (dp[idx][open][close] != -1)
                return dp[idx][open][close];

            if (s[idx] == '*') {
                return dp[idx][open][close] = solve(idx + 1, open + 1, close) ||
                                              solve(idx + 1, open, close + 1) ||
                                              solve(idx + 1, open, close);
            }
            return dp[idx][open][close] = solve(idx + 1, open + (s[idx] == '('),
                                                close + (s[idx] == ')'));
        };

        memset(dp,-1,sizeof(dp));
        return solve(0,0,0);
    }
};