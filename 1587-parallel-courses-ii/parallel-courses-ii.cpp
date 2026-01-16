class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        vector<int> degree(n + 1, 0);
        vector<vector<int>> graph(n + 1);

        for (auto& edge : dependencies) {
            int u = edge[0];
            int v = edge[1];

            degree[v]++;
            graph[u].push_back(v);
        }

        unordered_map<int, int> dp;

        function<int(int, vector<int>&)> solve = [&](int mask,
                                                     vector<int>& deg) -> int {
            if (mask == (1 << n) - 1)
                return 0;

            if (dp.find(mask) != dp.end())
                return dp[mask];

            vector<int> canTaken;
            for (int node = 1; node <= n; node++) {
                if (deg[node] == 0 && (mask & (1 << (node - 1))) == 0) {
                    canTaken.push_back(node);
                }
            }

            int minv = INT_MAX;
            if ((int)canTaken.size() <= k) {
                int newmask = mask;
                for (int& node : canTaken) {
                    for (auto& nb : graph[node]) {
                        deg[nb]--;
                    }
                    newmask |= (1 << (node - 1));
                }
                minv = min(minv, 1 + solve(newmask, deg));
            } else {
                int len = canTaken.size();
                for (int num = 1; num < (1 << len); num++) {
                    if (__builtin_popcount(num) == k) {
                        int newmask = mask;
                        vector<int> newdeg = deg;
                        for (int bit = 0; bit < len; bit++) {
                            if (num & (1 << bit)) {
                                int c = canTaken[bit];
                                for (auto& nb : graph[c]) {
                                    newdeg[nb]--;
                                }
                                newmask |= (1 << (c - 1));
                            }
                        }
                        minv = min(minv, 1 + solve(newmask, newdeg));
                    }
                }
            }
            return dp[mask] = minv;
        };
        return solve(0, degree);
    }
};
