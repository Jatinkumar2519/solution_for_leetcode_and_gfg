class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        static int dp[100001][2];

        int inf = 1e5;
        function<int(int, int)> solve = [&](int i, int swaped) -> int {
            if (i == nums1.size())
                return 0;

            if (dp[i][swaped] != -1)
                return dp[i][swaped];

            int minv = inf;

            if (i == 0) {
                minv = min({minv, 1 + solve(i + 1, true), solve(i + 1, false)});
            } else {
                int prev1 = nums1[i - 1];
                int prev2 = nums2[i - 1];

                if (swaped) {
                    swap(prev1, prev2);
                }

                if (prev1 < nums1[i] && prev2 < nums2[i]) {
                    minv = min(minv, solve(i + 1, false));
                }
                if (prev1 < nums2[i] && prev2 < nums1[i]) {
                    minv = min(minv, 1 + solve(i + 1, true));
                }
            }

            return dp[i][swaped] = minv;
        };

        memset(dp, -1, sizeof(dp));
        return solve(0, 0);
    }
};