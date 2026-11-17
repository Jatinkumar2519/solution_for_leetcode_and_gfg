class Solution {
public:
    int minimumChanges(string s, int m) {
        int n = s.length();

        auto getCost = [&](int i, int j, int k) -> int {
            int count = 0;
            for (int p = 0; p < k; p++) {

                string str;
                for (int q = p; q < (j - i + 1); q += k) {
                    str.push_back(s[q + i]);
                }

                int l = 0;
                int r = str.length() - 1;

                while (l <= r) {
                    count += (str[l] != str[r]);
                    l++;
                    r--;
                }
            }

            return count;
        };

        vector<vector<int>> cost(n, vector<int>(n));
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                int minv = INT_MAX;

                for (int d = 1; d * d <= len; d++) {
                    if (len % d == 0) {
                        minv = min(minv, getCost(i, j, d));

                        int x = len / d;

                        if (x != d && x < len) {
                            minv = min(minv, getCost(i, j, x));
                        }
                    }
                }

                cost[i][j] = minv;
            }
        }

        if (m == 1) return cost[0][n - 1];

        int dp[201][101];
        function<int(int, int)> solve = [&](int idx, int k) -> int {
            if (idx == n)
                return (k == 0) ? 0 : INT_MAX;
            if (k == 0)
                return INT_MAX;

            if (dp[idx][k] != -1)
                return dp[idx][k];

            int minv = INT_MAX;
            for (int j = idx + 1; j < n; j++) {

                int res = solve(j + 1, k - 1);
                if (res != INT_MAX) {
                    minv = min(minv, res + cost[idx][j]);
                }
            }

            return dp[idx][k] = minv;
        };

        memset(dp, -1, sizeof(dp));
        return solve(0, m);
    }
};