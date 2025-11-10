#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        // Precompute log values for RMQ
        vector<int> lg(n + 1);
        lg[1] = 0;
        for (int i = 2; i <= n; i++)
            lg[i] = lg[i / 2] + 1;

        int len = lg[n] + 1;
        vector<vector<int>> table(n, vector<int>(len));

        // Build Sparse Table
        for (int i = 0; i < n; i++) table[i][0] = nums[i];
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; (i + (1 << j)) <= n; i++) {
                table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }

        // Store indices for each unique value
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < n; i++) pos[nums[i]].push_back(i);

        // RMQ function
        auto getMin = [&](int l, int r) -> int {
            int k = lg[r - l + 1];
            return min(table[l][k], table[r - (1 << k) + 1][k]);
        };

        // Memoization to avoid repeated computation
        unordered_map<long long, int> memo;
        auto key = [&](int l, int r) -> long long {
            return ((long long)l << 32) | (unsigned)r;
        };

        function<int(int, int)> solve = [&](int l, int r) -> int {
            if (l > r) return 0;
            if (l == r) return nums[l] != 0 ? 1 : 0;

            long long state = key(l, r);
            if (memo.count(state)) return memo[state];

            int minv = getMin(l, r);
            if (minv == 0) { // skip zero regions
                int i = l, ans = 0;
                while (i <= r) {
                    while (i <= r && nums[i] == 0) i++;
                    int start = i;
                    while (i <= r && nums[i] != 0) i++;
                    if (start <= r) ans += solve(start, i - 1);
                }
                return memo[state] = ans;
            }

            // one operation for removing minv
            int ans = 1;
            vector<int>& arr = pos[minv];

            auto it1 = lower_bound(arr.begin(), arr.end(), l);
            auto it2 = upper_bound(arr.begin(), arr.end(), r);

            int prev = l;
            for (auto it = it1; it != it2; ++it) {
                int idx = *it;
                if (idx > prev) ans += solve(prev, idx - 1);
                prev = idx + 1;
            }
            if (prev <= r) ans += solve(prev, r);

            ans = min(ans, r - l + 1);

            return memo[state] = ans;
        };

        return solve(0, n - 1);
    }
};
