class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {

                int val = max({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});

                if (board[i - 1][j - 1] == 'E') {
                    dp[i][j] = 0;
                } else if (board[i - 1][j - 1] == 'S') {
                    dp[i][j] = (val == -1) ? 0 : val;
                } else if (board[i - 1][j - 1] != 'X') {
                    dp[i][j] =
                        (val == -1) ? val : (board[i - 1][j - 1] - '0') + val;
                }
            }
        }

        int target = dp[n][n];

        int mod = 1e9 + 7;
        int memo[101][101][1800];

        int dirx[3] = {0, 1, 1};
        int diry[3] = {1, 1, 0};

        function<int(int, int, int)> solve = [&](int i, int j, int k) -> int {
            if (k > target)
                return 0;
            if (board[i][j] == 'S')
                return (target == k);

            if (memo[i][j][k] != -1)
                return memo[i][j][k];

            int count = 0;
            for (int d = 0; d < 3; d++) {
                int ni = i + dirx[d];
                int nj = j + diry[d];

                if (ni < n && nj < n && 'X' != board[ni][nj]) {
                    int add = (board[ni][nj] >= '1' && board[ni][nj] <= '9')
                                  ? board[ni][nj] - '0'
                                  : 0;

                    // move only if this neighbour can still lead to an optimal
                    // score
                    if (dp[ni + 1][nj + 1] != -1 &&
                        dp[ni + 1][nj + 1] == dp[i + 1][j + 1] + add) {

                        count = (count + solve(ni, nj, k + add)) % mod;
                    }
                }
            }

            return memo[i][j][k] = count;
        };
        memset(memo, -1, sizeof(memo));

        return {target, solve(0, 0, 0)};
    }
};