class Solution {
public:
    int wiggleMaxLength(vector<int>& tokenArray) {
        int n = tokenArray.size();
        int dp[1002][1001][3];

        function<int(int, int, int)> solve = [&](int prev, int curr, int flag) {
            if (curr == n)
                return 0;
            if (dp[prev + 1][curr][flag] != -1)
                return dp[prev + 1][curr][flag];

            int maxv = solve(prev, curr + 1, flag);

            if (prev == -1) {
                maxv = max(maxv, 1 + solve(curr, curr + 1, flag));
            } else if (tokenArray[curr] != tokenArray[prev]) {
                int newFlag = (tokenArray[prev] - tokenArray[curr] < 0) ? 1 : 2;

                if (flag != newFlag) {
                    maxv = max(maxv, 1 + solve(curr, curr + 1, newFlag));
                }
            }

            return dp[prev + 1][curr][flag] = maxv;
        };

        memset(dp, -1, sizeof(dp));
        return solve(-1, 0, 0);
    }
};