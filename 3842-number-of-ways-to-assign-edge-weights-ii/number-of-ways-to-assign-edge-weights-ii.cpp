class Solution {
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {
        const int mod = 1e9 + 7;

        int n = edges.size() + 1;
        int len = 1;

        while ((1 << len) <= n) len++;

        vector<int> depth(n);
        vector<vector<int>> tree(n);
        vector<vector<int>> up(n, vector<int>(len, -1));

        for (auto &edge : edges) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;

            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        function<void(int, int)> dfs = [&](int node, int par) {
            up[node][0] = par;

            for (int i = 1; i < len; i++) {
                int p = up[node][i - 1];

                if (p != -1) {
                    up[node][i] = up[p][i - 1];
                }
            }

            for (int nxt : tree[node]) {
                if (nxt == par) continue;

                depth[nxt] = depth[node] + 1;
                dfs(nxt, node);
            }
        };

        dfs(0, -1);

        auto getLCA = [&](int u, int v) {
            if (depth[u] < depth[v]) {
                swap(u, v);
            }

            int diff = depth[u] - depth[v];

            for (int i = 0; i < len; i++) {
                if (diff & (1 << i)) {
                    u = up[u][i];
                }
            }

            if (u == v) {
                return u;
            }

            for (int i = len - 1; i >= 0; i--) {
                if (up[u][i] != -1 && up[u][i] != up[v][i]) {
                    u = up[u][i];
                    v = up[v][i];
                }
            }

            return up[u][0];
        };

        auto getDist = [&](int u, int v) {
            int lca = getLCA(u, v);

            return depth[u] + depth[v] - 2 * depth[lca];
        };

        vector<int> pow2(n);
        pow2[0] = 1;

        for (int i = 1; i < n; i++) {
            pow2[i] = (pow2[i - 1] * 2LL) % mod;
        }

        vector<int> result;

        for (auto &query : queries) {
            int u = query[0] - 1;
            int v = query[1] - 1;

            int d = getDist(u, v);

            if (d == 0) {
                result.push_back(0);
            } else {
                result.push_back(pow2[d - 1]);
            }
        }

        return result;
    }
};