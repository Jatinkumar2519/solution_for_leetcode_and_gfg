class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();

        vector<int> dp(n, -1);

        function<int(int)> solve = [&](int node) -> int {
            if (dp[node] != -1)
                return dp[node];

            int maxv = 1;
            for (int i = 1; i <= d && node + i < n; i++) {
                if (arr[node] <= arr[node + i])
                    break;

                maxv = max(maxv, 1 + solve(node + i));
            }

            for (int i = 1; i <= d && node - i >= 0; i++) {
                if (arr[node] <= arr[node - i])
                    break;

                maxv = max(maxv, 1 + solve(node - i));
            }

            return dp[node] = maxv;
        };
        int ans = 1;

        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(i));
        }

        return ans;
    }
};