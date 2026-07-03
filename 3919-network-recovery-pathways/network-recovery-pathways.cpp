class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                         long long k) {
        using ll = long long;
        int n = online.size();

        int inf = LLONG_MAX;

        vector<int> degree(n, 0), topo;
        vector<vector<pair<int, int>>> graph(n);

        ll left = inf;
        ll right = 0;

        for (auto& edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            degree[edge[1]]++;

            right += edge[2];
            left = min(left, 1ll * edge[2]);
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto [nn, _] : graph[node]) {
                if (--degree[nn] == 0) {
                    q.push(nn);
                }
            }
        }
        
        auto feasible = [&](ll mid) {
            const ll INF = LLONG_MAX;
            vector<ll> dp(n, INF);

            if (!online[0] || !online[n - 1])
                return false;

            dp[0] = 0;

            for (int node : topo) {
                if (dp[node] == INF)
                    continue;

                for (auto [nn, cst] : graph[node]) {
                    if (!online[nn] || cst < mid)
                        continue;

                    dp[nn] = min(dp[nn], dp[node] + cst);
                }
            }

            return dp[n - 1] <= k;
        };

        ll res = -1;
        while (left <= right) {
            ll mid = (left + right) / 2;

            if (feasible(mid)) {
                res = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return res;
    }
};