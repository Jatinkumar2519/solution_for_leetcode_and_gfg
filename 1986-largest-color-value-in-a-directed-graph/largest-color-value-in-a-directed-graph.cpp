class Solution {
public:

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        vector<int> degree(n, 0);
        vector<vector<int>> graph(n);

        // Build graph
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            degree[v]++;
        }

        // Cycle detection using topological sort
        queue<int> q;
        int start = 0;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 0){
                start = i;
                q.push(i);
            }
        }

        int count = 0;
        vector<int> topo;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            count++;
            topo.push_back(node);
            for (int& nn : graph[node]) {
                if (--degree[nn] == 0) {
                    q.push(nn);
                }
            }
        }

        // Cycle exists
        if (count != n) return -1;

        vector<vector<int>> dp(n, vector<int>(26, 0));
        int ans = 0;

        for (int u : topo) {
            int c = colors[u] - 'a';
            dp[u][c]++;
            ans = max(ans, dp[u][c]);

            for (int v : graph[u]) {
                for (int col = 0; col < 26; col++) {
                    dp[v][col] = max(dp[v][col], dp[u][col]);
                }
            }
        }

        return ans;
    }
};
