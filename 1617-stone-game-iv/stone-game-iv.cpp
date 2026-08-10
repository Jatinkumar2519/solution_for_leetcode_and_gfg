class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);

        for (int num = 1; num <= n; num++) {
            for (int j = 1; j * j <= num; j++) {
                int square = j * j;

                if (!dp[num - square]) {
                    dp[num] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};