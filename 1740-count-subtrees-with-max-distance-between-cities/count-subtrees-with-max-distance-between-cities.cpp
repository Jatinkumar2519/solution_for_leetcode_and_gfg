class Solution {
public:
    void getDepth(vector<vector<int>>& graph, int node, int par, int depth,int& dnode, int& maxdepth) {
        if (maxdepth < depth) {
            dnode = node;
            maxdepth = depth;
        }
        for (auto& nn : graph[node]) {
            if (nn == par)
                continue;
            getDepth(graph, nn, node, depth + 1, dnode, maxdepth);
        }
    }
    vector<int> countSubgraphsForEachDiameter(int n,vector<vector<int>>& edges) {
        vector<vector<bool>> valid(n + 1, vector<bool>(n + 1, false));
        for (auto& edge : edges) {
            valid[edge[0]][edge[1]] = true;
            valid[edge[1]][edge[0]] = true;
        }
        vector<vector<int>> subset;
        function<void()> getSubset = [&]() -> void {
            for (int i = 1; i < (1 << n); i++) {
                if (__builtin_popcount(i) <= 1)
                    continue;
                vector<int> sub;
                for (int j = 0; j < n; j++) {
                    if (i & (1 << j)) {
                        sub.push_back(j + 1);
                    }
                }
                subset.push_back(sub);
            }
        };
        function<vector<vector<int>>(vector<int>)> getGraph =
            [&](vector<int> vertices) -> vector<vector<int>> {
            vector<vector<int>> graph(n + 1);
            for (int i = 0; i < vertices.size(); i++) {
                for (int j = i + 1; j < vertices.size(); j++) {
                    int u = vertices[i];
                    int v = vertices[j];
                    if (valid[u][v]) {
                        graph[u].push_back(v);
                        graph[v].push_back(u);
                    }
                }
            }
            return graph;
        };
        function<bool(vector<int>, vector<vector<int>>)> isConnected =
            [&](vector<int> vertices, vector<vector<int>> graph) -> bool {
            unordered_set<int> vis;
            function<void(int)> dfs = [&](int node) {
                vis.insert(node);
                for (auto& nn : graph[node]) {
                    if (!vis.count(nn))
                        dfs(nn);
                }
            };
            dfs(vertices[0]);
            return vertices.size() == vis.size();
        };
        function<int(vector<int>)> solve = [&](vector<int> vertices) -> int {
            int node = vertices[0];
            vector<vector<int>> graph = getGraph(vertices);
            if (!isConnected(vertices, graph))
                return 0;
            int end1 = node;
            int maxdepth1 = 0;
            getDepth(graph, node, -1, 0, end1, maxdepth1);
            int end2 = end1;
            int maxdepth2 = 0;
            getDepth(graph, end1, -1, 0, end2, maxdepth2);
            return maxdepth2;
        };
        getSubset();
        vector<int> answer(n - 1, 0);
        for (auto& arr : subset) {
            int res = solve(arr);
            if (res > 0) {
                answer[res - 1]++;
            }
        }
        return answer;
    }
};