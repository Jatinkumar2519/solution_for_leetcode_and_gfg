class Solution {
public:
    void selectK(vector<int>& arr, int k, vector<vector<int>>& res) {
        int n = arr.size();
        for (int mask = 0; mask < (1 << n); mask++) {
            if (__builtin_popcount(mask) == k) {
                vector<int> curr;
                for (int j = 0; j < n; j++) {
                    if (mask & (1 << j)) {
                        curr.push_back(arr[j]);
                    }
                }
                res.push_back(curr);
            }
        }
    }

    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> degree(n + 1, 0);
        vector<vector<int>> graph(n + 1);

        for (auto &edge : relations) {
            int u = edge[0], v = edge[1];
            degree[v]++;
            graph[u].push_back(v);
        }

        map<int, int> dp;
        function<int(int)> solve = [&](int mask) -> int {
            if (__builtin_popcount(mask) == n) return 0; // all courses done
            if (dp.find(mask) != dp.end()) return dp[mask];

            vector<int> available;
            for (int i = 1; i <= n; i++) {
                if (degree[i] == 0 && ((mask & (1 << (i - 1))) == 0)) {
                    available.push_back(i);
                }
            }

            if (available.empty()) return INT_MAX;

            vector<vector<int>> groupOfK;
            if ((int)available.size() <= k) {
                groupOfK.push_back(available);
            } else {
                selectK(available, k, groupOfK);
            }

            int res = INT_MAX;
            for (auto &group : groupOfK) {
                int newMask = mask;
                for (int node : group) {
                    newMask |= (1 << (node - 1));
                    for (int nn : graph[node]) degree[nn]--;
                }

                int ans = solve(newMask);
                if (ans != INT_MAX) res = min(res, 1 + ans);

                // backtrack
                for (int node : group) {
                    for (int nn : graph[node]) degree[nn]++;
                }
            }

            return dp[mask] = res;
        };

        return solve(0);
    }
};
