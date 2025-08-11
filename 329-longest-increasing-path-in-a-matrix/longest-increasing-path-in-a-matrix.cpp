class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int dirx[] = {-1, 1, 0, 0};
        int diry[] = {0, 0, -1, 1};
        vector<vector<int>> dp(n, vector<int>(m, -1));
        function<int(int, int)> solve = [&](int x, int y) -> int {
            if (dp[x][y] != -1)
                return dp[x][y];
            int maxv = 0;
            for (int d = 0; d < 4; d++) {
                int nx = x + dirx[d];
                int ny = y + diry[d];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    if (mat[x][y] < mat[nx][ny]) {
                        maxv = max(maxv, 1 + solve(nx, ny));
                    }
                }
            }
            return dp[x][y] = maxv;
        };
        int maxlen = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maxlen = max(maxlen, 1 + solve(i, j));
            }
        }
        return maxlen;
    }
};