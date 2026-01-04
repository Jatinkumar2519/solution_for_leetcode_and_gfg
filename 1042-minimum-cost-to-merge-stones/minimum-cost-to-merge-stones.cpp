class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int dp[101][101];
        int n = stones.size();

        if ((n - 1) % (k - 1) != 0)
            return -1;

        vector<int> prefix(n);
        prefix[0] = stones[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        function<int(int, int)> solve = [&](int left, int right) -> int {
            if (left == right)
                return 0;
            if (dp[left][right] != -1)
                return dp[left][right];

            int minv = INT_MAX;
            for (int i = left; i < right; i += k - 1) {
                minv = min(minv, solve(left, i) + solve(i + 1, right));
            }

            if ((right - left) % (k - 1) == 0) {
                minv += (left == 0) ? prefix[right]
                                    : prefix[right] - prefix[left - 1];
            }
            return dp[left][right] = minv;
        };

        memset(dp, -1, sizeof(dp));
        return solve(0, n - 1);
    }
};